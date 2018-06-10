using ASP_MVC.DataAbstractionLayer;
using ASP_MVC.Models;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.Web.Mvc;

namespace ASP_MVC.Controllers
{
    public class BookRoomController : Controller
    {
        // GET: BookRoom
        public ActionResult BookRoom()
        {
            return View();
        }

        public JsonResult GetRoom()
        {
            string id = (string)Request.Params["id"];

            DAL dal = new DAL();
            Room room = dal.GetRoom(id);
            List<Room> list = new List<Room>();
            list.Add(room);
            return Json(list, JsonRequestBehavior.AllowGet);

        }
        public JsonResult SaveBooking()
        {
            DAL dal = new DAL();
            string rid = (string)Request.Params["rid"];
            string cid = (string)Request.Params["cid"];
            string start = (string)Request.Params["startDate"];
            string end = (string)Request.Params["endDate"];
            try
            {
                dal.SaveBooking(rid, cid, start, end);
            }
            catch(Exception ex)
            {
                return Json("Cannot book this room on this dates!", JsonRequestBehavior.AllowGet);
            }
            return Json("Succes", JsonRequestBehavior.AllowGet);

        }
    }
}