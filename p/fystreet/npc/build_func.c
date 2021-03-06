//build_func.c      zip@hero  2000.1.27 建房功能
#include <ansi.h>
#define __ROOMDIR__ "/p/fystreet/"
int fileoperate(object ob,object me);
void init()
{  add_action("do_build","build");
   add_action("do_sign","sign");}

int do_build(string arg)
{ int roomid;
  if(arg!="here") return 0;
  if(this_object()->query("owner")!=this_player()->query("id")) return 0;
  this_object()->set_temp("buildfinish",0);
  roomid=(int)environment(this_object())->query("roomid");
  if(!roomid) {write("say 这儿还是不适合建房子，找别的地方吧？");return 1;}
  this_object()->set("roomid",roomid);
  write("say 好，就这儿了。");
  write("emote 掏出一个文件夹翻开，往上记了些什么。");
  write("say 给你的房子取一个好名字吧，最好是3～7个中文，可以用(help color)来看颜色。");
  write("请输入房间名：");
  input_to("get_room_name");
return 1;
}
int get_room_name(string arg)  //输入房子名称
{ if(!arg||arg=="") {write("say 嗯，还是先想好吧。想好了再(build here)。");return 1;}
  if(arg=="help color") 
  { write("Zmud4可能区别不出普通与亮色，往上的版本则正常。
$RED$ - "+RED"红色"NOR+"		$HIR$ - "+HIR"亮红色"NOR+"
$GRN$ - "+GRN"绿色"NOR+"		$HIG$ - "+HIG"亮绿色"NOR+"
$YEL$ - "+YEL"土黄色"NOR+"		$HIY$ - "+HIY"黄色"NOR+"
$BLU$ - "+BLU"深蓝色"NOR+"		$HIB$ - "+HIB"蓝色"NOR+"
$MAG$ - "+MAG"浅紫色"NOR+"		$HIM$ - "+HIM"粉红色"NOR+"
$CYN$ - "+CYN"蓝绿色"NOR+"		$HIC$ - "+HIC"天青色"NOR+"
$WHT$ - "+WHT"浅灰色"NOR+"		$HIW$ - "+HIW"白色"NOR+"
系统自动会在字串尾端加一个$NOR$恢复正常颜色。\n");
  write("请输入房间名：");input_to("get_room_name");return 1;}
  arg=replace_string(arg,"$RED$",RED);arg=replace_string(arg,"$GRN$",GRN);
  arg=replace_string(arg,"$YEL$",YEL);arg=replace_string(arg,"$BLU$",BLU);
  arg=replace_string(arg,"$MAG$",MAG);arg=replace_string(arg,"$CYN$",CYN);
  arg=replace_string(arg,"$WHT$",WHT);arg=replace_string(arg,"$HIR$",HIR);
  arg=replace_string(arg,"$HIG$",HIG);arg=replace_string(arg,"$HIY$",HIY);
  arg=replace_string(arg,"$HIB$",HIB);arg=replace_string(arg,"$HIM$",HIM);
  arg=replace_string(arg,"$HIC$",HIC);arg=replace_string(arg,"$HIW$",HIW);
  arg=replace_string(arg,"$NOR$",NOR);arg+=NOR;
  this_object()->set("roomname",arg);
  write("say 好名字，"+arg);
  write("emote 在文件夹子里写了几笔。");
  write("say 你想要什么样的房子呢？描述一下外观吧，只要一行就好。");
  write("请输入房间外观：");input_to("get_room");
return 1;
}
int get_room(string arg) //输入外观描述
{ string *dir=({"东","西"});
  string msg;object me=this_object();
  if(!arg||arg=="") {write("say 外观确定了就不能再改了，先想好再(build here)吧。");return 1;}
// 用于扩展功能select()
  me->set("roomlong",arg);
  write("emote 的笔在文件夹子上飞快地记着。");
  write("say 好了，你看看对不对。");
  msg ="\n      地点：神州大街"+chinese_number((int)me->query("roomid")/100)+"号"+dir[(int)me->query("roomid")%2];
  msg+="\n      房名："+(string)me->query("roomname");
  msg+="\n      外观："+"这里是"+this_player()->query("name")+"的"+(string)me->query("roomname")+"。\n    "+me->query("roomlong");
  write(msg+"\n\n");
  write("say 如果没什么问题，请在这儿签个字(sign)。");
  this_object()->set_temp("buildfinish",1);
return 1;
}

int do_sign(string arg)
{ object ob,me;
  me=this_player();ob=this_object();
  if(ob->query("owner")!=me->query("id")) return 0;
  if(!(ob->query_temp("buildfinish"))) return 0;
  message_vision("$N大笔一挥，签上自己大名："+me->query("name")+"。\n",me);
  write("say 你的房子最晚是下次系统重起后盖好，先去家具铺子看看有什么家具吧，好装修一下房子。");
  write("say 家具铺就在街口往西，我先回去了。");
  write("chat "+this_player()->query("name")+"("+this_player()->query("id")+")的豪宅即将修建完成。");
  fileoperate(me,ob);
  me->delete_temp("inbuild");
  me->set("roomid",ob->query("roomid"));
  me->add("created_room",ob->query("roomid"));
destruct(ob);  
return 1;
}
int fileoperate(object ob,object me)
{ string *dir=({"东","西"});
  string file,writefile;
  file=read_file(__ROOMDIR__"outdoor.c");
  file=replace_string(file,"#define ID 109","#define ID "+(string)me->query("roomid"));
  if((int)me->query("roomid")%2) file=replace_string(file,"west","east");
  file=replace_string(file,"某位房主",ob->query("name"));
  file=replace_string(file,"自建房屋",me->query("roomname"));
  file=replace_string(file,"xxxxx",ob->query("id"));
  file=replace_string(file,"不注意的话，很难发现它的存在。",me->query("roomlong"));
  file=replace_string(file,"owner_id",ob->query("id"));
  writefile=__ROOMDIR__+"street"+(string)me->query("roomid");
  find_object(writefile)->delete("roomid");writefile+=".c";
  write_file(writefile,file,1);
  //added by lion@hero here
  //房间增加个人留言板。
  file=read_file(__ROOMDIR__"std_board.c");
  file=replace_string(file,"/p/fystreet/indoor.c","/p/fystreet/room/"+ob->query("id")+"_room.c");
  file=replace_string(file,"std_board",ob->query("id")+"_board");
  writefile=__ROOMDIR__+"board/"+ob->query("id")+"_board.c";
  write_file(writefile,file,1);
  file=read_file(__ROOMDIR__"indoor.c");
  file=replace_string(file,"#define ID 109","#define ID "+(string)me->query("roomid"));
  file=replace_string(file,"owner_id",ob->query("id"));
  file=replace_string(file,"房名",me->query("roomname"));
  file=replace_string(file,"/p/fystreet/board/std_board","/p/fystreet/board/"+ob->query("id")+"_board");
  //modified by lion@hero here
  //玩家房间单独一个目录存放。
  writefile=__ROOMDIR__+"room/"+ob->query("id")+"_room.c";
  write_file(writefile,file,1);
  writefile=__DIR__"room.list";file=read_file(writefile);
  file+=":"+ob->query("name")+","+me->query("roomid")+":";
  write_file(writefile,file,1);
return 1;
}
