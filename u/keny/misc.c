#include <ansi.h>
inherit ROOM;
string look_jia();

void create()
{
        set("short",HIC"���﷿"NOR);
        set("long",@LONG
�����ǻ�������﷿��ǽ�ϸ�����������������ǽ�������һ����(jia)��
��ܰ��������������ı��С�
LONG
         );
        
        set("valid_startroom",1); 
        set("valid_startroom",1);
        set("no_steal",1);
        set("no_death",1);          
        set("no_fight",1);
        set("exits", ([
              "west" : __DIR__ "workroom",
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
case"whip": weapon = new("/clone/weapon/bian");
break;
case"xiao": weapon = new("/clone/weapon/tiexiao");
break;
case"armor": weapon = new("/clone/armor/tiejia");
break;
case"money": weapon = new("/clone/money/thousand-cash");
break;
case"gu": weapon = new("/u/keny/obj/gu"); 
break;
default:        return notify_fail("�Ҳ���"+type+"\n");
}
        if(weapon->move(me)) {
      message_vision("$N�ӱ�������ȡ��һ"+weapon->query("unit")+weapon->name()+"��\n", me);
  } else {
 destruct(weapon);
}
return 1;
}
string look_jia()
{
       string msg;
        msg = " "HIC" ����ָ�� "NOR" get "HIR"(��Ʒ)"NOR" from jia \n";
        msg+= ""HIC"---------------------------------------------------"NOR" \n";
        msg+= ""HIY"��"NOR"(jian)��"HIR"��"NOR"(dao)��"GRN"��"NOR"(stick)��"CYN"��"NOR"(staff)��"YEL"��"NOR"(whip) \n";
        msg+= ""HIC"����"NOR"(armor)��"HIY"Ǯ"NOR"(money)��\n";
        msg+= ""HIC"---------------------------------------------------"NOR" \n";
        return msg;
}


