// Code of ShenZhou
// Room: /d/shaolin/fumoquan.c
// Date: YZC 96/01/19

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "��շ�ħȦ");
        set("long", @LONG
���ô������������ϸ����˸�������һ�˵Ĵ󶴣��и�����
¶����ɫɮ��һ�ǣ��ƺ�ס�����ˡ�������һƬ���ƺ�����Ĵ�
��ͺͺ�ģ��ƺ������ܴ����������´�ݲ�����
LONG
        );

        set("exits", ([
                "out" : __DIR__"qyping",
        ]));

        set("objects",([
                CLASS_D("shaolin") + "/du-nan" : 1,
                CLASS_D("shaolin") + "/du-e" : 1,
                CLASS_D("shaolin") + "/du-jie" : 1,
        ]));
        set("cost", 2);
        setup();
}

void init()
{       
        mapping fam;
        string name;    
        
        fam = this_player()->query("family");
        name = this_player()->query("name");

        if ( mapp(fam) && fam["family_name"] == "������" && fam["generation"] <= 37 && (name[0..1] == "��" || name[0..1] == "��")) return;

        if( interactive( this_player()) ) {
                message_vision(HIR "ͻȻ�侢���ݺᣬ��������������������͵ع�����˲�����\n" +
                "����һ�����Եı��У��糤ì����˰������������ֱ���$N��ͷ��\n" +
                "�أ�������Ҫ�����̶�����$NһƳ�䣬����������ɮ�־�������  \n" +
                "��֮�У���ȫ���ֱ���$N������$N��������������֮�̺����Ͻ�  \n" +
                "ħ�󷨵Ľ�շ�ħȦ��\n\n" NOR, this_player());
        }

        if ( mapp(fam)
        && fam["generation"] > 36 
        && fam["family_name"] == "������" 
        && this_player()->query("qi") < 300 ) 
        {

                message_vision(HIR "$N��һ����ɽ������ľ������У���ʱ���˳�ȥ !\n" NOR, this_player());
        }

}

int valid_leave(object me, string dir)
{

        if( dir == "out" && present("puti zi", me) )
        {
                return notify_fail("�㲻�ܴ����������뿪��ħȦ !\n");
        }
        me->delete_temp("fighter");

        return ::valid_leave(me, dir);
}
