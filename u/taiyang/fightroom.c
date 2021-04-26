#include <ansi.h>
inherit ROOM;
string look_jia();

void create()
{
        set("short",HIY"健身房"NOR);
        set("long",@LONG
       这里是太阳神的健身房，偌大的房间中央站了一个木人，墙角有一个兵器架(jia)， 
随便挑一把试试手吧。
LONG
         );
        
        set("valid_startroom",1); 
        set("valid_startroom",1);
        set("no_steal",1);
        set("exits", ([
              "south" : __DIR__ "workroom",
        ]));          
                    set("objects",([ 
                       "/u/taiyang/muren" : 1, 
       ])); 
       set("item_desc", ([
                "jia": (: look_jia :),
         ]));
       
       setup();
}
void init()
{
add_action("do_get", "get");
}
int do_get(string arg)
{
        object weapon, me=this_player();
        string type;
        if(!arg) return 0;
        if(me->is_busy()) return 0;
        if (sscanf(arg, "%s from jia", type) != 1) return 0;

      if (!wizardp(me)) return 0;  
switch(type)
{
case"jian": weapon = new("/clone/weapon/qinggang-jian");
break;
case"dao": weapon = new("/clone/weapon/gangdao");
break;
case"stick": weapon = new("/d/gaibang/obj/yellowbang");
break;
case"staff": weapon = new("/clone/weapon/gangzhang");
break;
case"whip": weapon = new("/clone/weapon/changbian");
break;
case"xiao": weapon = new("/clone/weapon/tiexiao");
break;
case"armor": weapon = new("/clone/armor/tiejia");
break;
case"money": weapon = new("/clone/money/thousand-cash");
      break;
break;
      case"qi": weapon = new("/clone/wiz/mihun"); 
default:        return notify_fail("找不到"+type+"\n");
}
        if(weapon->move(me)) {
      message_vision("$N从兵器架上取下一"+weapon->query("unit")+weapon->name()+"。\n", me);
  } else {
 destruct(weapon);
}
return 1;
}
string look_jia()
{
       string msg;
        msg = " "HIC" 请用指令 "NOR" get "HIR"(物品)"NOR" from jia \n";
        msg+= ""HIC"---------------------------------------------------"NOR" \n";
        msg+= ""HIY"剑"NOR"(jian)，"HIR"刀"NOR"(dao)，"GRN"棒"NOR"(stick)，"CYN"杖"NOR"(staff)，"YEL"鞭"NOR"(whip) \n";
        msg+= ""HIC"铁甲"NOR"(armor)，"HIY"钱"NOR"(money)。\n";
        msg+= ""HIC"---------------------------------------------------"NOR" \n";
        return msg;
}


