using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SQLite;
using System.Data;

namespace ConsoleApp1
{
    public static class SQLiteService
    {
        #region [PUBLIC]Methods
        public static DataTable ExtractDB(string path, string dbField)
        {
            DataTable db = new DataTable();
            string sql = $"SELECT * FROM {dbField}";
            //using (SQLiteConnection connection = new SQLiteConnection($"Data Source={path};Version=3;"))
            using (SQLiteConnection connection = new SQLiteConnection(@"Data Source =  " + Environment.CurrentDirectory + "\\localBD"))
            {
                SQLiteCommand command = new SQLiteCommand(sql, connection);
                SQLiteDataAdapter adapter = new SQLiteDataAdapter(command);
                adapter.Fill(db);
            };
            return db;
        }
        #endregion
    }
}
