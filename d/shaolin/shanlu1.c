// /d/shaolin/shanlu1.c

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
ɽ·������У��鲼��ʯͷʹ��������������ۡ��ߵ�����
���Ѿ��������������Ҫ֧�Ų�ס�ˣ������ʱ͵��ͣ�½Ų���
�������Ͼͻ��н���Ժ��ɮ��ץ��ȥ������Ժ�����ġ�
LONG
        );

        set("exits", ([
                "southdown" : __DIR__"riverbank",
				"northeast" : __DIR__"xiaojing1",
        ]));

        set("outdoors", "shaolin");
        set("cost", 3);
        setup();
}
int valid_leave(object me, string dir)
{
        int current_jingli, current_dodge,bili,shenfa;
		string fam;
		object obj;
        current_jingli = me->query("jingli");
		bili = me->query("str");
		shenfa = me->query("dex");
		fam = me->query("family/family_name");
		obj = present("shui tong", me);
        if (dir == "northeast" && current_jingli >10 && (fam == "������") &&(obj) && (obj->query("full")))
        {
                me->set("jingli",current_jingli-random(20));
                me->improve_skill("dodge", random(shenfa));
				me->improve_skill("cuff",random(bili));
                write("��ҧ��������ɽ�£��Ѿ��۵ô��������ˡ�\n");
        }

        else if (dir == "southeast" && current_jingli <= 10)
        {
                write("���۵�ʵ���߲����ˣ�����һ����ʲôҲ��֪���ˡ�\n");
                me->unconcious();
                return notify_fail("");
        }

        return ::valid_leave(me, dir);
}

