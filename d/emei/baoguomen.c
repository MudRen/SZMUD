// Code of ShenZhou
// baoguomen.c ������ɽ��
// Shan: 96/09/29

inherit ROOM;

void create()
{
        set("short", "������ɽ��");
        set("long", @LONG
������Ϊ���ҳ���֮�Ż���ɽ��(gate)����һ����ҡ������骻�������
����ӳ���ɴ�һ·�����Ͽ�ʼ�Ƕ���ɽ��������ɽ��һ�������ʯ��·��
LONG
        );
        set("exits", ([
                "west" : __DIR__"baoguo",
                "northdown" : __DIR__"shijie1",
        ]));

        set("objects", ([
                __DIR__"npc/xiang-ke.c": 1,
        ]) );

	set("outdoors", "emei");
        set("item_desc",([
            "gate"       :
"	\n"
"�����������������աաաաաաաաաաաաաաաա�\n"
"�����������������աա��������������������������ա�\n"
"�����������������աա������������������¡������ա�\n"
"�����������������աա��������������������������ա�\n"
"�����������������աաաաաաաաաաաաաաաա�\n"
        ]));

        set("valid_startroom", 1);

	set("cost", 0);
        setup();
//      "/clone/board/emei1_b"->foo();

}

// To check and record emei dizi's shen every time she/he leaves emei.

int valid_leave(object me, string dir)
{
//        int current_shen;

//        current_shen = me->query("shen");
        if (dir == "northdown" && me->query("family/family_name") == "������")
        {
//                me->set("emei_shen",current_shen);
		if (me->query("gender") == "Ů��")
		{
                	write("���µ���������˻��ֵ���ʦ����أ����������ҪС�ģ���Ҫ������ʦ�����\n");
		}
		else
		{
			write("���µ���������˻��ֵ���ʦ����أ����������ҪС�ģ���Ҫ������ʦ�����\n");
                }
        }

        return ::valid_leave(me, dir);
}

