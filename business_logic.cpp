/// $Header
/// ============================================================================
///		Author		: M. Ivanchenko
///		Date create	: 04-03-2017
///		Date update	: 08-03-2017
///		Comment		:
/// ============================================================================

#include <QApplication>
#include <QFileDialog>
#include <QMessageBox>

#include "business_logic.h"
#include "dir_csv_exporter.h"

namespace cfmc
{

namespace monitoring
{

/// ############################################################################
///			class business_logic
/// ############################################################################

    /// ========================================================================
    ///		FUNCTIONS
    /// ========================================================================
    /// ------------------------------------------------------------------------
    ///	choose_dir( )
    /// ------------------------------------------------------------------------
    QString business_logic::choose_dir( )
    {
        return QFileDialog::getExistingDirectory(
                                                  nullptr,
                                                  tr("Open Directory"),
                                                  "/home",
                                                  QFileDialog::ShowDirsOnly
                                                  | QFileDialog::DontResolveSymlinks
                    );
    }

    /// ------------------------------------------------------------------------
    ///	export_data(const QString &s_path, const QString &s_filter)
    /// ------------------------------------------------------------------------
    void business_logic::export_data( const QString &s_path, const QString &s_filter )
    {
        QString f_filter = s_filter;
        if( f_filter.isEmpty( ) )
        {
            f_filter = "*.*";
        }
        dir_csv_exporter::export_path( s_path, f_filter );

        QMessageBox::information( nullptr, tr("info"), tr("finished") );
    }

}//namespace monitoring

}//namespace cfmc
