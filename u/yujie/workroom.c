//Made by wengyu

//wengyu's home :) 

inherit ROOM;
#include <ansi.h> 



void create() 

{ 

set("short",HIW"草儿的精神家园"NOR); 

set("long", @LONG 
   这里是个没有物质概念的空间。一来到这里，你的灵魂就好象已经从肉体中
飞升了出去，进入了一种祥和的境界，天地好象已和你融为一体，你的思维开始
了无限制的膨胀。你第一次意识到，原来空间可以这么大，可以和你这么接近....
精神家园正无私地向你敞开。
   
   伴随着漫天飞舞、似幻似真的小精灵（jingling），面前呈现出一条条迷离的
精神通道，它们可以带你经历：快乐（kuaile）、悲伤（beishang）、
痛苦（tongku）、兴奋（xingfen）、信任（xinren）.......

LONG 
); 
set("item_desc", ([ 

"jingling" :"这是一些有着晶莹身躯和五彩双翼的小精灵，她们虽然只是一种
纯精神体的存在，但却永远散发出动人的活力，挥洒着精神国度的魔法。你可以
用你的精神去召唤(zhaohuan)她们！\n", 

])); 



set("exits", ([ 
"movie" : "/kungfu/class/movie/center",

"clb" : "/d/forest/clzoulang2",





"out" :__DIR__"trafic", 


])); 


set("no_steal",1); 

set("valid_startroom",1); 


set("objects", ([ //sizeof() == 1
__DIR__"npc/baby":1,
])); 

setup(); 

call_other("/clone/board/yujie_b", "???");

} 

void init() 
{ 
add_action("do_setone", "setone"); 
add_action("do_setall", "setall"); 
add_action("do_deleteall", "deleteall"); 
add_action("do_deall", "deall"); 
add_action("do_clone", "myclone"); 
add_action("do_giveall", "giveall"); 
add_action("do_zhaohuan", "zhaohuan"); 
add_action("do_new", "donew"); 
} 


int do_new(string arg) 
{
object me,ob;
me = this_player();
ob=new(arg);
ob->move(me);
return 1;
}

int do_setone(string arg)
{
object me,ob; 
me=find_player(arg);
return 1;
}
int do_zhaohuan(string arg)
{
object me,ob; 
me = this_player(); 
if (!wizardp(this_player())) 
{
 write("你又不是巫师！哪里来的魔力呀！\n");
 return 0;
}

if( !arg || arg=="jingling" )
{
 if (present("jingling",this_object()))
 {
  write("精灵已经被召唤了！\n");
  return 1;
 } 
 else
 {
  message_vision(BLINK+HIW"在$N强大精神力量的召唤下，周围的空间忽然亮了起来,奇妙的事情发生了！\n"NOR+BLINK+HIC"只见漫天的精灵都渐渐的聚集在$N的四周欢呼雀跃，赶快(look)一下吧...\n"NOR,me);
  ob=new(__DIR__"npc/jingling");
  ob->move(this_object());
  return 1;
 }
}
write("你要召唤什么？\n"); return 0;
}


int do_setall(string arg)
{
    object ob, *ob_list, ob1;
    int i;
    string *str;

    object me = this_player();

    if(!arg) return 0;

      str = explode(arg," ");

      if (str[1])
      {
          ob_list = users();
    for(i=0; i<sizeof(ob_list); i++)
    {
        ob = ob_list[i];
        ob->set(str[0],str[1]);
     }
     }
    return 1;
}
int do_deleteall(string arg)
{
    object ob, *ob_list, ob1;
    int i;
    string *str;

    object me = this_player();

    if(!arg) return 0;

          ob_list = users();
    for(i=0; i<sizeof(ob_list); i++)
    {
        ob = ob_list[i];
        ob->delete(arg);
     }
    return 1;
}

int do_giveall(string arg)
{
    object ob, *ob_list, ob1;
    int i;
    string str;

object me = this_player();

    if(!arg) return notify_fail("指令格式 giveall 物品路径\n");

    if( sscanf(arg, "%*s.c") != 1) return notify_fail("路径不合法，无法找到物品。\n");

    if( file_size(arg) < 0 )               return notify_fail("没有这个档案(" + arg + ")。\n");    

    seteuid(getuid());

    ob_list = users();
    for(i=0; i<sizeof(ob_list); i++)
    {
        ob = ob_list[i];
        ob1 = new(arg);
        ob1 -> move(ob); 
        tell_object(ob, HIG "天上突然掉下了什么东西到你的口袋里，你最好检查一下。\n" NOR);
    }
    str = sprintf("共有 %d 位玩家得到了%s。\n", sizeof(ob_list), arg->query("name"));    
    me->start_more(str);
    return 1;
}

int do_clone(string arg)
{
  object obj , me = this_player();
  string err, msg;
  seteuid( geteuid(me) );
  if (!arg) arg = me->query("cwf");
  if (!arg)    return notify_fail("你要复制什么物件？\n");

  arg = resolve_path(me->query("cwd"), arg);
  if( sscanf(arg, "%*s.c") != 1 ) arg += ".c";
  me->set("cwf", arg);

  if( file_size(arg) < 0 )
    return notify_fail("没有这个档案(" + arg + ")。\n");

  if( !find_object(arg) )
  {
    err = catch(call_other(arg, "???"));
    if (err)
    {
      write("载入失败：" + err + "\n");
      return 1;
    }
  }

  err = catch(obj = new(arg));
  if (err)
  {
    write("复制失败：" + err + "\n");
    return 1;
  }

  if (!objectp(obj))
    return notify_fail("这样东西不能被复制。\n");
  if( !obj->is_character() && obj->move(me) )
  {
    write(obj->query("name") + "复制成功\，放在你的物品栏。\n");
    obj->set("cloner", geteuid(me));
    return 1;
  }
  if( obj->move(environment(me)) )
  {
    write(obj->query("name") + "复制成功\，放在这个房间。\n");
    obj->set("cloner", geteuid(me));
    return 1;
  }

  destruct(obj);
  return notify_fail("无法复制不能移动的物件(" + arg + ")。\n");
}

int do_deall(string arg)
{	
	object 	*list,user,thisob,me = this_player();
        int i,j;
	
	
	list = users();
	
        for(i=0; i<sizeof(list); i++)
    	{
        	user = list[i];
        	if (objectp (thisob = present(arg,user)) )
        	{	destruct(thisob);
                        j++;
        	}
        }
        write("共清除"+chinese_number(j)+"个玩家身上的指定物件。\n");
        return 1;
}
        		


