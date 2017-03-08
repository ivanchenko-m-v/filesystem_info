/// $Header
/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 04-03-2017
///		Date update	: 08-03-2017
///		Comment		:
/// ============================================================================
#ifndef __PANEL_BUTTONS_H__
#define __PANEL_BUTTONS_H__

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

namespace cfmc
{

namespace monitoring
{

/// ############################################################################
///			class panel_buttons
/// ############################################################################
    class panel_buttons : public QWidget
    {
        Q_OBJECT
    /// ========================================================================
    ///		CONSTRUCTORS/DESTRUCTOR
    /// ========================================================================
    private:
        /// --------------------------------------------------------------------
        panel_buttons( const panel_buttons &rhs );

    public:
        /// --------------------------------------------------------------------
        explicit panel_buttons(QWidget *parent = 0);
        /// --------------------------------------------------------------------
        virtual ~panel_buttons( );

    /// ========================================================================
    ///		PROPERTIES
    /// ========================================================================
        /// --------------------------------------------------------------------
        QString files_filter( ) const;

    /// ========================================================================
    ///		FUNCTIONS
    /// ========================================================================
    private:
        /// --------------------------------------------------------------------
        void initialize( );
        void init_layout( );
        QWidget* init_txt_filter( );
        QWidget* init_btn_choose( );
        QWidget* init_btn_export( );
        QWidget* init_btn_exit( );

    /// ========================================================================
    ///		OPERATORS
    /// ========================================================================
    private:
        /// --------------------------------------------------------------------
        panel_buttons& operator=( const panel_buttons &rhs );

    /// ========================================================================
    ///			SIGNALS
    /// ========================================================================
    signals:
        void choose_dir( );
        void export_data( );
        void exit_app( );

    /// ========================================================================
    ///			FIELDS
    /// ========================================================================
    private:
        const int _STRETCH_BTN_ = 100;
        const int _STRETCH_TXT_ = 300;
        const int _STRETCH_SPACE_ = 1000;

        QLineEdit*   _txt_filter = nullptr;

        QPushButton* _btn_choose = nullptr;
        QPushButton* _btn_export = nullptr;
        QPushButton* _btn_exit = nullptr;

    };//class panel_buttons
/// ############################################################################
/// ----------------------------------------------------------------------------

}//namespace monitoring

}//namespace cfmc

#endif // __PANEL_BUTTONS_H__
