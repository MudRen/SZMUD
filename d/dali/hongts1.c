// Code of ShenZhou
// Room: /d/dali/hongts1.c

inherit ROOM;

void create()
{
	set("short", "��ʥ����");
	set("long", @LONG
�����Ǻ�ʥ�����ڲ�������ǽ���϶����з��裬������
����̧ͷ���������Կ�������������«����ɡ�ǡ����ּ�
�������еȡ�ɡ�ǳɰ˽��Σ����Ϲ��з��졣
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"hongts2.c",
  "down" : __DIR__"hongtj.c",
]));
	set("no_clean_up", 0);
	set("cost", 3);

	setup();
//	replace_program(ROOM);
}
int valid_leave(object me, string dir)
{
        int current_jingli, current_dodge;

        current_jingli = me->query("jingli");
        if (dir == "up" && current_jingli >10)
        {
                me->set("jingli",current_jingli-random(20));
                me->improve_skill("dodge", random(10));
                write("������һ��¥����Щ���ˡ�\n");
        }

        else if (dir == "up" && current_jingli <= 10)
        {
                write("���۵��߲����ˣ���Ȼ��ð���ǣ����˹�ȥ��\n");
                me->unconcious();
                return notify_fail("");
        }
        return ::valid_leave(me, dir);
}

