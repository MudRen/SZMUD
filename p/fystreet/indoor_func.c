// indoor_func.c zip@hero 2000.1.27 房子内部功能
void enter_desc(string arg);
void init()
{  add_action("do_open","open");
   add_action("do_close","close");
   add_action("do_zhuangxiu","zhuangxiu");
   add_action("do_dazareng","dazareng");
   add_action("do_yaoqing","yaoqing");
   add_action("do_kickout","kickout");
}

int do_open(string arg)
{  object ob;
   if(arg!="door") 
   return notify_fail("你要打开什么？\n");
   if(!ob=find_object("/p/fystreet/street"+(string)ID)) 
   ob=load_object("/p/fystreet/street"+(string)ID);
   if(ob->query("exits/enter")) return notify_fail("门不正大开着吗？\n");
   message_vision("$N将房门打开。\n",this_player());
   ob->set("exits/enter",__DIR__+(string)this_object()->query("owner")+"_room");
   tell_room(ob,this_player()->name()+"将房门打开。\n");
return 1;
}
int do_close(string arg)
{  object ob;
   if(arg!="door") return notify_fail("你要关上什么？\n");
   if(!ob=find_object("/p/fystreet/street"+(string)ID)) 
   ob=load_object("/p/fystreet/street"+(string)ID);
   if(!ob->query("exits/enter")) return notify_fail("咦，门开着吗？\n");
   ob->delete("exits/enter");
   message_vision("$N将房门关上。\n",this_player());
   tell_room(ob,this_player()->name()+"将房门关上。\n");
return 1;
}
int do_zhuangxiu()
{  if(this_object()->query("owner")!=this_player()->query("id")) return notify_fail("这是你的房间吗？\n");
   if(this_player()->query("jiaju")<3) return notify_fail("你的家具还不够三件。\n");
   if(this_object()->query("long")!=" 这是一座刚建好的大房子,就等着装修了。\n") 
     return notify_fail("这不都好好的吗，就嫌家具旧了啊？\n");
   write("请输入完整的房间描述，三十到三百个中文字。\n\n");
   this_player()->edit((:enter_desc:));
return 1;}
void enter_desc(string arg)
{  if((strlen(arg)<60)||(strlen(arg)>600))
    {write("对不起，房间描述必须是三十到三百个中文字。\n");return;}
   write("好，房间描述是：\n   "+arg);
   write("\n你确定吗？[yes|no]->");
   input_to("check_yes",arg);
return;}
void check_yes(string arg,string text)
{  string file,filename,bakname;
   if(arg!="yes") {write("还是别急吧。\n");return;}
   filename=__DIR__+this_player()->query("id")+"_room.c";
   file=read_file(filename);write_file(__DIR__+this_player()->query("id")+"_room.bak",file,1);
   file=replace_string(file,"这是一座刚建好的大房子,就等着装修了。",text);
   if(!write_file(filename,file,1)) write("write file fail.\n");
   this_object()->set("long",text);this_player()->delete("jiaju");
   message_vision("$N将房间好好装修了一番。大功告成！\n",this_player());
return;}
int do_dazareng()
{  if(this_object()->query("owner")!=this_player()->query("id")) return notify_fail("这是你的房间吗？捣什么乱！\n");
   if(this_object()->query("long")=="这是一座刚建好的大房子,就等着装修了。\n") 
     return notify_fail("看这里空空如也的，拿什么砸啊？\n");
   message_vision("$N决定对自己的房间来一次打砸扔！\n",this_player());
   write("要重新装修的话可是要重新买家具的，想好了！[yes|no]->");
   input_to("check_yess");
return 1;}
void check_yess(string arg)
{  string file;
   if(arg!="yes") {message_vision("$N面对自己亲手布置的房间，哎，怎么也下不了手。\n",this_player());return;}
   file=read_file(__DIR__+this_player()->query("id")+"_room.bak");
   write_file(__DIR__+this_player()->query("id")+"_room.c",file,1);
   this_object()->set("long","这是一座刚建好的大房子,就等着装修了。\n");
   message_vision("$N叫道：旧的不去，新的不来！只听一阵噼里啪啦叮呤咣啷，兼以满屋烟尘斗乱，爽！\n",this_player());
return;}

//added by lion@hero
//邀请其他人来这里.
int do_yaoqing(string arg)
 {
     string id;
    int roomid;
  object ob,room;
  object me=this_player();
  room = this_object();
  id = geteuid(me);
  if(room->query("owner")!=geteuid(me))
  return notify_fail("你不是这里的主人,不能邀请客人.\n");
  if(!arg||arg=="")
  return notify_fail("命令格式:yaoqing <id>\n");
  ob = LOGIN_D->find_body(arg);
  if (!ob) return notify_fail("咦... 有这个人吗?\n");
   if(present(arg,room))
   return notify_fail("你要邀请的人就在这个房间呀？\n");
  message_vision("$N邀请$n来这里做客。\n",me,ob);
  tell_object(ob,HIY"\n"+me->name()+"热情邀请您到"+room->query("short")+"去做客.\n"NOR);
   roomid=me->query("roomid");
  tell_object(ob,room->query("short")+"就在神州大街"+chinese_number(roomid/100)+"号"+((roomid%2)?"西":"东")+"。\n");
  return 1;
 } 
 
//把不速之客赶走。
int do_kickout(string arg)

 {
   string id;
  object ob,room;
  object me=this_player();
  room = this_object();
  id = geteuid(me);
  if(room->query("owner")!=id)
  return notify_fail("你不是这里的主人,不能赶人.\n");
  if(!arg||arg=="")
  return notify_fail("命令格式:kickout <id>\n");
  ob = present(arg,this_object());
  if (!ob) return notify_fail("这人没在这个房间啊!\n");
  message_vision("$N把$n赶了出去。\n",me,ob);
  tell_object(ob,HIY"\n"+me->name()+"不欢迎你在那里做客，你还是走吧。\n"NOR);
  room=find_object("/p/fystreet/street"+(string)ID);
  if(!room)
 room=load_object("/p/fystreet/street"+(string)ID);
  ob->move(room);
  return 1;
 }  
 

