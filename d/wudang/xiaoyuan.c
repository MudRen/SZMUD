        // Code of ShenZhou
// xiaoyuan.c ��ɽСԺ
// by Xiang
// Modified by xQin 11/00

inherit ROOM;
#include <room.h>
void create()
{
        set("short", "��ɽСԺ");
        set("long", @LONG
���Ǻ�ɽ��һ��СԺ�����ü�򵥵�������һ����һ����һ�Ρ�һ����
����Ҳû�б��ʲ��Ƚ�����עĿ����ǽ�Ϲ���һ�ѽ�����������䵱��
ɽ��ʦ��������������ڡ�������һ������(ce)��
LONG
        );

        set("exits", ([
                "north" : __DIR__"hs_xiaolu",
        ]));
        set("objects", ([
                CLASS_D("wudang") + "/zhang" : 1 ]));
        create_door("north", "����", "south", DOOR_CLOSED);
        set("cost", 1);
        setup();
}
void init()
{
        add_action("do_kill","kill");
                
                //Add by Scatter
                add_action("do_fan","fan");
                add_action("do_fan","flip");
}

int do_fan(string arg)
{
        if (arg != "ce")
        {
                return 1;
        }

        write("�㿴���Ȿ����д��\n");
        write("�������߽���Ϊ�������������䵱ɽһ�򹩷�����ۡ���������һ����Ѫ������\n��������������ǰ�Ĺ��߶��������𳤽��ͺ�ˮ֮�����ɽ����ɽ�����볤���鶯���ڹ����أ�\n����������һ��һ�ߣ����Ǽ����������ص��������ԣ��������һ�׾����޷����书������\n�����书���Ǵӹ��߶�ɽ�������磬��ɽ���ݻ��������书��ɭȻ���У����޼��㡣\n�����书�����ɫΪ������Ϊ���˺�ʹ������ͬ��ʮ���˸��ֺ�ʹһ�㣬������֮�ͣ�\nʵ���޿ɱ��⡣\n\n�Ȿ���Ͽ������е����...\n\n");
        return 1;
}


int do_kill(string arg)
{
        object ob, ob1, me = this_player();

        if ( !arg || arg == "" ) return 0;

        if ( !ob=present(arg, environment(me)) ) return 0;
        if ( !ob1=present("zhang sanfeng", environment(me)) ) return 0;
        if ( ob1 == ob ) return 0;
        if ( ob->query("family/family_name") == "�䵱��" ) {
                message_vision("$Nһ����Ц���󵨿�ͽ����Ҳ̫С����ͷ�����˰ɣ�\n ", ob1);
                ob1->kill_ob(me);
        }
        return 0;
}

