using ASP_MVC.DataAbstractionLayer;
using ASP_MVC.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace ASP_MVC.Controllers
{
    public class PricesController : Controller
    {
        // GET: Prices
        public ActionResult Prices()
        {
            return View();
        }
        public JsonResult GetPriced()
        {
            List<Room> rooms = null;
            DAL dal = new DAL();

            string min = (string)Request["min"];
            string max = (string)Request["max"];

            rooms = dal.GetPriced(min, max);

            return Json(rooms, JsonRequestBehavior.AllowGet);
        }
    }
}