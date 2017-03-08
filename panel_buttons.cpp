/// $Header
/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 04-03-2017
///		Date update	: 08-03-2017
///		Comment		:
/// ============================================================================

#include <QHBoxLayout>
#include <QLabel>

#include "panel_buttons.h"

namespace cfmc
{

namespace monitoring
{
/// ############################################################################
///			class panel_buttons
/// ############################################################################

    /// ========================================================================
    ///		CONSTRUCTORS/DESTRUCTOR
    /// ========================================================================

    /// ------------------------------------------------------------------------
    ///	panel_buttons( )
    /// ------------------------------------------------------------------------
    panel_buttons::panel_buttons(QWidget *parent) :
        QWidget(parent)
    {
        this->initialize( );
    }
    /// ------------------------------------------------------------------------
    ///	~panel_buttons( )
    /// ------------------------------------------------------------------------
    panel_buttons::~panel_buttons( )
    {

    }

    /// ========================================================================
    ///		PROPERTIES
    /// ========================================================================
    /// ------------------------------------------------------------------------
    ///	files_filter( )
    /// ------------------------------------------------------------------------
    QString panel_buttons::files_filter( ) const
    {
        if( this->_txt_filter == nullptr )
        {
            return "";
        }
        return this->_txt_filter->text( );
    }

    /// ========================================================================
    ///		FUNCTIONS
    /// ========================================================================

    /// ------------------------------------------------------------------------
    ///	initialize( )
    /// ------------------------------------------------------------------------
    void panel_buttons::initialize( )
    {
        this->init_layout( );
    }

    /// ------------------------------------------------------------------------
    ///	init_layout( )
    /// ------------------------------------------------------------------------
    void panel_buttons::init_layout( )
    {
        QHBoxLayout *layout = new QHBoxLayout;

        //
        //_txt_filter
        //
        layout->addWidget( this->init_txt_filter( ), this->_STRETCH_TXT_ );

        layout->addStretch( this->_STRETCH_SPACE_ );
        //
        //_btn_choose
        //
        layout->addWidget( this->init_btn_choose( ), this->_STRETCH_BTN_ );
        //
        //_btn_export
        //
        layout->addWidget( this->init_btn_export( ), this->_STRETCH_BTN_ );
        //
        //_btn_exit
        //
        layout->addWidget( this->init_btn_exit( ), this->_STRETCH_BTN_ );

        this->setLayout(layout);
    }

    /// ------------------------------------------------------------------------
    ///	init_txt_filter( )
    /// ------------------------------------------------------------------------
    QWidget* panel_buttons::init_txt_filter( )
    {
        QHBoxLayout *layout = new QHBoxLayout;

        QLabel *lbl = new QLabel( tr("Filter:") );
        layout->addWidget( lbl );

        this->_txt_filter = new QLineEdit;
        layout->addWidget( this->_txt_filter );

        QWidget *widget = new QWidget(this);
        widget->setLayout( layout );

        return widget;
    }

    /// ------------------------------------------------------------------------
    ///	init_btn_choose( )
    /// ------------------------------------------------------------------------
    QWidget* panel_buttons::init_btn_choose( )
    {
        this->_btn_choose = new QPushButton;
        this->_btn_choose->setText( tr("Choose Dir") );
        QObject::connect(
                       this->_btn_choose, &QPushButton::clicked,
                       this, &panel_buttons::choose_dir
                        );

        return this->_btn_choose;
    }

    /// ------------------------------------------------------------------------
    ///	init_btn_export( )
    /// ------------------------------------------------------------------------
    QWidget* panel_buttons::init_btn_export( )
    {
        this->_btn_export = new QPushButton;
        this->_btn_export->setText( tr("Export") );
        QObject::connect(
                       this->_btn_export, &QPushButton::clicked,
                       this, &panel_buttons::export_data
                        );

        return this->_btn_export;
    }

    /// ------------------------------------------------------------------------
    ///	init_btn_exit( )
    /// ------------------------------------------------------------------------
    QWidget* panel_buttons::init_btn_exit( )
    {
        this->_btn_exit = new QPushButton;
        this->_btn_exit->setText( tr("Exit") );
        QObject::connect(
                        this->_btn_exit, &QPushButton::clicked,
                        this, &panel_buttons::exit_app
                        );

        return this->_btn_exit;
    }

}//namespace monitoring

}//namespace cfmc
