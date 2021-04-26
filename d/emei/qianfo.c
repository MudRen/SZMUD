// Code of ShenZhou
// qianfo.c ǧ����(�鴻ƺ)
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "ǧ����");
	set("long", @LONG
�˴��Ǻ鴻ƺǧ���֡�ɽ��Сƺ�ӣ�������͵��ϣ��廷�뻤���������
��ᰣ�Ϫ���ᶣ��ƺ�Ϲ�ľ���裬ͤͤ��ǣ�ɽ����͸������Ʈ�Σ���Ϊ�ľ�
�������˴��������������������������ɣ���ɽ��������Ϊ������ν��ɽ�б�
���꣬�մ�ʪ���¡����������Ϊ��۵ġ��鴻���꡹���˴��������ģ�����
���죬����������;�����ǡ���ʮ�ŵ��ա������¾�������ջ����������
LONG
	);
	set("exits", ([
		"southwest" : __DIR__"dao99",
		"north" : __DIR__"zhandao2",
		"enter" : __DIR__"qianfo1",
	]));

        set("no_clean_up", 0);
        set("fjing", 1);
        set("outdoors", "emei" );

	set("cost", 0);
	setup();
//	replace_program(ROOM);
}

int valid_leave(object me, string dir)
{
        int current_jingli, current_dodge;

        current_jingli = me->query("jingli");
        if (dir == "southwest" && current_jingli >10)
        {
                me->set("jingli",current_jingli-random(20));
                me->improve_skill("dodge", random(5));
                write("���ؾ�ʮ�ŵ�����������һ�󣬾��ú��ۡ�\n");
        }

        else if (dir == "southwest" && current_jingli <= 10)
        {
                write("���۵��߲����ˣ���Ȼ��ð���ǣ����˹�ȥ��\n");
                me->unconcious();
                return notify_fail("");
        }
        return ::valid_leave(me, dir);
}
