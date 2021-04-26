// July 31,2000
// Code by April
// /gumu/liangongshi2.c
// update april 01/08/19

#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
        set("short","������");

        set("long",@LONG
��ʯ����״������ǰ���෴��������խ����Ϊ���Ρ����߰�Բ������
��������,�Ҷ�ʯ��(ceiling)��Ҳ��������㻨�Ʒ��š�������һ�����š�
LONG);

                  set("item_desc",(["ceiling" : "
    �Ҷ����䴦�����������Σ������߰�ʮ������ģ���ƺ�����Ů�࣬��
ʽ������ͬ��ȫ����һ˿˿ϸ������ɢ�䡣
\n"]));

                set("exits",([ 
                                "northeast" : __DIR__"biaoshi2",
                                "northwest" : __DIR__"jianshi2",
                                "west": __DIR__"liangongshi4",
                                "south" : __DIR__"zhangshi2",
                                        ]));

                  set("objects", ([ 
                                "/kungfu/class/gumu/npc/baiyi1": 1, 
                                ]) );

                create_door("west", "����", "east", DOOR_CLOSED);
                
                set("cost",1);
                setup();
}
void init()
{
        add_action("do_study", "study");
        add_action("do_study", "du");
}
int valid_leave(object me, string dir)
{
	if ( me->query("gender") == "����" && dir == "west" && !wizardp(me) )
		return notify_fail("������㣬����Ů�᷿��\n");
	if (dir =="west" && me->query("family/family_name")!="��Ĺ��" ) {
		if (objectp(present("baiyi girl", environment(me))))
			return notify_fail("������Ů���ֵ�ס�����ȥ·���˴����ɽ��أ���ֹ����\n");
	}      

        return ::valid_leave(me, dir);
}
int do_study(string arg)
{
        object me;
        int f1, f2;

        me = this_player();

        if ( !arg || ( arg != "ceiling" ) )
                return notify_fail("ʲô��\n");

		if (me->is_busy()) return notify_fail("��æ���أ�\n");
                
        if ( (int)me->query_skill("literate", 1) < 1){
            write("�㲻ʶ�֣���ѧ���Ļ�(literate)�ɡ�\n");
                        return 1;
                }

        f1 = me->query_skill("yunu-xinjing", 1);
        f2 = me->query_skill("yunu-xinfa", 1);

        if ((f1 >= 30) || (f2>= 30)){
			write("���о��˰���һ������\n");
			command("sigh");
			write("���������ѧ������˵̫�����ˡ�\n");
                return 1;
        }

        if (me->query("jing")<15) {
                write("������ͷ���ۻ����������컨���ϵ��֡�\n");
                return 1;
        }

        me->receive_damage("jing", 10, "����˥�߶���");

        message_vision("$N��ר���ж��컨���ϵĹ�Ĺ�ķ���\n", me);

		me->improve_skill("yunu-xinfa", me->query_int()/3);
		write("���Ķ��컨���ϵ��ľ����ƺ��Թ�Ĺ�书�����ĵ��ˡ�\n");
        
                return 1;
}
