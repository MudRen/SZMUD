// Code of ShenZhou
// Jay 8/9/96

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ�������Ϸ����ķ��ı���ǽ�Ϲ���һ����ġ������ġ���
��������(tie)�����Ű���һ�Ŵ�(bed)��
LONG
        );
        set("exits", ([
		"west" : __DIR__"huilang",
	]));

	set("objects", ([
		__DIR__"npc/tubiweng" : 1,
	]));

	set("item_desc", ([
                "tie" : "����д�ţ�
	�Ὣ����
	��������ϣ�
	�ͽ������
	ս����������
	�����׳�գ�\n",
		"bed" : "����ͨͨ��һ�Ŵ���\n",
	]));
        set("no_clean_up", 0);
	set("cost", 0);
	setup();
        replace_program(ROOM);
}
