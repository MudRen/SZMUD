// Code of ShenZhou
// baoguo.c ������
// Shan: 96/09/22

inherit ROOM;

int do_study(string);

void create()
{
        set("short", "������");
        set("long", @LONG
�������Ƕ�üɽ�����Ժ֮һ��������ɽ���죬���յ���۵�߷��
�����ߣ���ģ��󡣵��ڷ������������������������ڷ����Ծ���������
����������һ��������(ta)������������Լ����ɴ�����¡�
LONG
        );
        set("exits", ([
                "enter" : __DIR__"baoguo1",
		"southwest" : __DIR__"fuhuroad",
                "east" : __DIR__"baoguomen",
		"west" : __DIR__"baoguoxi",
        ]));

        set("objects", ([
                __DIR__"npc/xiang-ke.c": 1,
        ]));

	set("outdoors", "emei");
        set("item_desc",([
            "ta"        :
"    ����һ��ʮ������ͭ�����������������ף��������ѹ���С����ǧ�߰�\n"
"��֮�࣬�����С����Ͼ���ȫ��������֣���ұ��������񹤼��ɣ���������\n"
"����֮����\n"
        ]));

	set("cost", 1);
        setup();
}

void init()
{
        add_action("do_study", "study");
        add_action("do_study", "du");
}


int do_study(string arg)
{
        object me;
	int ml, pl;

        me = this_player();

        if ( !arg || ( arg != "ta" ) )
                return notify_fail("ʲô��\n");

        if ( (int)me->query_skill("literate", 1) < 1)
                return notify_fail("�㲻ʶ�֣���ѧ���Ļ�(literate)�ɡ�\n");

	ml = me->query_skill("mahayana", 1);
	pl = me->query_skill("persuading", 1);

	if ( (ml >= 60 && pl <= ml) || ml >= 2*pl ) {
		write("������������˲��ܼ�����ߴ�����ͷ���Ϊ��\n");
		return 1;
	}

	if (me->query("jing")<40) {
		write("������ͷ���ۻ������������ϵ��֡�\n");
                return 1;
        }

        me->receive_damage("jing", 30, "����˥�߶���");

        message_vision("$N��ר���ж��������ϵġ����Ͼ�����\n", me);

        if ( ml < 100 )
        {
                me->improve_skill("mahayana", me->query_int());
                write("����Ż������ϵĻ��Ͼ���ĥ��һ���ƺ��Դ�����ͷ������ĵá�\n");
                return 1;
        }

        write("����Ż���������һ���������������˵�ķ���̫��ǳ�ԣ�������˵�����������ˡ�\n");

        return 1;
}

