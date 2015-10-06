#include "updatedialog.h"
#include "ui_updatedialog.h"
#include <QTextStream>
#include <QListWidgetItem>
#include <QList>

UpdateDialog::UpdateDialog(UpdateInfoModel *model, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateDialog)
{
    ui->setupUi(this);
	
    _model = model;

    fillView(model);
    SetupRefreshButton();
}

QIcon *UpdateDialog::getIcon()
{
#if 0
  QSvgRenderer renderer(QString(":/icons/uhuru_grey.svg"));

  QPixmap pixmap(24, 24);
  //  pixmap.fill(0xaaA08080);  // partly transparent red-ish background

  // Get QPainter that paints to the image
  QPainter painter(&pixmap);
  painter.setPen(Qt::white);
  renderer.render(&painter);

  //  QIcon icon(":/icons/uhuru.svg");
  // QGraphicsSvgItem *red = new QGraphicsSvgItem();
  // QGraphicsColorizeEffect *effect = new QGraphicsColorizeEffect();
  // red.setGraphicsEffect(effect);

  return new QIcon(pixmap);
#endif
#if 1
  return new QIcon(":/icons/uhuru_grey.svg");
#endif
}

void UpdateDialog::SetupRefreshButton()
{
   QPushButton *RefreshButton =  findChild<QPushButton*>("RefreshButton");

   // Create connexion onClick() -> RefreshUpdateInfo
   connect(RefreshButton, SIGNAL(clicked()), this, SLOT(RefreshUpdateInfo()));
}

void UpdateDialog::RefreshUpdateInfo()
{
    fillView(_model);
}

void UpdateDialog::fillView(UpdateInfoModel *model)
{

    struct uhuru_info * info = NULL;
    struct uhuru_module_info **m;
    struct uhuru_base_info **b;
 
    info = model->RefreshUpdateInfo();

    //info_to_stdout(info);
    QListWidget *pListWidget = findChild<QListWidget*>("listWidget"); 

    fprintf(stderr, "Update global status : %d\n", info->global_status);

    if (info->module_infos != NULL) {
       for(m = info->module_infos; *m != NULL; m++){
            AddModuleItem(m, pListWidget);
       }
    }

    uhuru_info_free(info); 
}

void UpdateDialog::AddModuleItem(struct uhuru_module_info **m, QListWidget *pListWidget)
{
    QIcon *icon_uhuru = getIcon();
    QIcon *icon_clamav = new QIcon(":/icons/clamav.ico");

    fprintf(stderr, "Module %s \n", (*m)->name );
    fprintf(stderr, "- Update date : %s \n", (*m)->update_date );
    fprintf(stderr, "- Update status : %d\n", (*m)->mod_status);

    // Find item if already exists
    QListWidgetItem *item = NULL;
    QString pattern = QString("Module ") +  QString((*m)->name);
    QList<QListWidgetItem *> items = pListWidget->findItems(pattern, Qt::MatchStartsWith);
    if(items.isEmpty())
    {
        item = new QListWidgetItem();
    }
    else
    {
        item = items.first();
    }

    // We retrieve the QString correspondig to the status
    QString status = getStatusQString((*m)->mod_status);

    // We format the line to be shown
    item->setText( QString("Module ") +  QString((*m)->name) + QString(" -- Last update : ") + QString((*m)->update_date) + QString(" -- ") + status);

    // Set Icon
    if(strncmp((*m)->name,"clamav",6) == 0)
    {
        item->setIcon(*icon_clamav);
    }
    else
    {
        item->setIcon(*icon_uhuru);
    }

    pListWidget->addItem(item);
}

QString UpdateDialog::getStatusQString(int status)
{
   switch(status){
     case UHURU_UPDATE_OK:
       return QString("OK");
     case UHURU_UPDATE_LATE:
       return QString("LATE");
     case UHURU_UPDATE_CRITICAL:
       return QString("CRITICAL");
     case UHURU_UPDATE_NON_AVAILABLE:
       return QString("NON_AVAILABLE");
     default:
       return QString("UNKNOWN");
   }
}

UpdateDialog::~UpdateDialog()
{
    delete ui;
}