// Code of ShenZhou
// Room: /ningyuan.c

inherit ROOM;

void create()
{
	set("short", "��Զ");
	set("long", @LONG
�����ǹ���פ���ľ������򡣳Ǹߺӿ��ر�ɭ�ϣ���¥�ϲ����д���
�Ĺٱ�פ�����������м��ź��»��ڣ��������ϡ������Լ����ٱ����ڼ��
�������˵���Ʒ����ʱ��������߳��֮����
LONG
	);

	set("exits", ([
		"southwest" : __DIR__"guandao3",
		"north" : __DIR__"lyddao1",
	]));

        set("outdoors", "changbai");
        set("cost", 2);

	setup();
	replace_program(ROOM);
}

