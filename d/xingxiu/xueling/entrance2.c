// Code of ShenZhou
// entrance1 for fighting ground

inherit ROOM;
#include <ansi.h>
#include "battlefield.h"

string look_jia();

int valid_leave(object who, string dir);

void create()
{
  set("short", HIG"�Խ�ͤ"NOR);
  set("long", @LONG
������ǽ��Խ�ɽׯ��Ӣ����ѡ����ֱ��еĵط��ˡ�����
���� (jia) �Ϸ����˸��ֵ�������������һЩ����ʲô�ġ��Ӵ�
������Ǳ��䳡�ˡ�
LONG
  );

  set("no_fight", 1);
  set("invalid_startroom", 1);
  set("exits", ([
		 "enter" : __DIR__"test_room1",
		 ]));
        set("item_desc", ([
                "jia": (: look_jia :),
        ]));

  setup();
}

void init()
{
    add_action("do_get", "get");
    disableCmds();
}

int valid_leave(object who, string dir)
{
    who->set("eff_qi", who->query("max_qi"));
    who->set("qi", who->query("max_qi"));
    who->set("eff_jing", who->query("max_jing"));
    who->set("jing", who->query("max_jing"));
    who->set("jingli", who->query("max_jingli"));
    who->set("neili", who->query("max_neili"));
    who->delete("env/wimpy");
    return ::valid_leave(who, dir);
}

int do_get(string arg)
{
        object weapon, me=this_player();
        string type;
        if(!arg) return 0;
        if(me->is_busy()) return 0;
        if (sscanf(arg, "%s from jia", type) != 1) return 0;
        switch (type) {
        case "zhen":    weapon = new("/clone/weapon/xiuhua");
			break;
        case "sword":   weapon = new("/clone/weapon/gangjian");
                        break;
        case "blade":   weapon = new("/clone/weapon/gangdao");
                        break;
        case "club":    weapon = new("/clone/weapon/teigun");
                        break;
        case "stick":   weapon = new("/clone/weapon/zhubang");
                        break;
        case "shezhang":   weapon = new("/clone/weapon/shezhang");
                        break;
        case "staff":   weapon = new("/clone/weapon/gangzhang");
                        break;
        case "falun":   weapon = new("/clone/weapon/falun");
                        break;
        case "whip" :   weapon = new("/clone/weapon/changbian");
                        break;
        case "armor":   weapon = new("/clone/armor/tiejia");
                        break;
        default:        return notify_fail("�Ҳ���"+type+"\n");
        }
 	weapon->set_temp("xueling", 1);
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
        msg = "����һ�������ܣ�ʮ�˰�������Ӧ�о��С�\n";
        msg+= "Ŀǰ������廨��(zhen), �ֽ�(sword)���ֵ�(blade)������(club)\n";
	msg+= "���(stick)������(staff)������(shezhang), ����(falun)������(whip)��\n";
	msg+= "����һЩ����(armor)��\n";
        msg+= "����ָ�get ���� from jia����ȡ����ֵı�������С�\n";
        return msg;
}

