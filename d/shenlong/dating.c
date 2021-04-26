// Code of ShenZhou
// ���� /d/shenlong/dating
// ALN Sep / 97

#include <ansi.h>
inherit ROOM;

string look_jia();

void create()
{
	set("short", "����");
	set("long", @LONG
��������һ������֮�У�����˶����������ݵ���ǧ��֮�ڣ�һȺȺ��
����Ů����ɫվ�ã�ÿ������֮ǰ��վ��һ��ͷĿ�����������кܶ���ڡ�
��������һ�ű�����(jia)��
LONG
	);

	set("exits", ([
                "east" : __DIR__"shibanlu",
		"out" : __DIR__"tingkou",
	]));

        set("cost", 1);

        set("objects", ([
         //        "kungfu/class/shenlong/qinglong" : 1,
                 "/d/shenlong/npc/qing" : 1,
                 "/d/shenlong/npc/bai" : 1,
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
        object weapon, me = this_player();
        string type;

        if(!arg) return 0;

        if( me->is_fighting() || me->is_busy() ) return 0;

        if( sscanf(arg, "%s from jia", type) != 1) return 0;

        if( time() < me->query("sg/weapontime") + 300 ) {
                tell_object(me, "��̫̰���ˣ����ǵ�һ�������ɡ�\n");
                return 1;
        }

        if( type != "armor" ) {
                if( (int)me->query_skill(type, 1) < 1 ) {
                        tell_object(me, "�㲻��������������\n");
                        return 1;
                }
        }

        switch(type) {
        case "sword":   if(me->query("gender") == "����") 
                                weapon = new("/clone/test/xiuhua");
                        else    weapon = new("/clone/weapon/gangjian");
                        break;
        case "blade":   weapon = new("/clone/weapon/gangdao");
                        break;
        case "stick":   weapon = new("/clone/weapon/zhubang");
                        break;
        case "staff":   weapon = new("/clone/weapon/gangzhang");
                        break;
        case "hammer":   weapon = new("/clone/test/falun");
                        break;
        case "whip" :   weapon = new("/clone/weapon/changbian");
                        break;
        case "armor":   weapon = new("/clone/armor/tiejia");
                        break;

        default:        tell_object(me, "�Ҳ���" + type + "\n");
                        return 1;
        }

        if( weapon->move(me) ) {
                message_vision("$N�ӱ�������ȡ��һ"+weapon->query("unit")+weapon->name()+"��\n", me);
                me->set("sg/weapontime", time());
        }  else {
                destruct(weapon);
        }
        return 1;
}

string look_jia() 
{
        string msg;

        msg = "����һ�������ܣ�ʮ�˰�������Ӧ�о��С�\n";
        msg+= "Ŀǰ����н�(sword)����(blade)����(stick)����(staff)����(hammer)��\n��(whip)������һЩ����(armor)��\n";
        msg+= "����ָ�get ���� from jia����ȡ����ֵı�������С�\n";
        return msg;
}






