// Code of ShenZhou
// liangongfang2.c ������
// xQin 11/00

inherit ROOM;

void create()
{
	set("short", "������" );
	set("long", @LONG
�������䵱���ӵ�������������ֽ�����ڣ����������Ͷ�������ֻ��
����һ��һ�Σ��������Ųݵ�����š������䵱��������ϥ���������Ϲۿ�
�����䵱�������䵱������ȭ���໥�д輼�ա��е��Ӽ�������������ͷ
΢Ц��ȴ����������
LONG
	);
	set("exits", ([
		"north" : __DIR__"xilang2",
		]));
	set("objects", ([
		"kungfu/class/wudang/yu.c" : 1,
		]));
		
	setup();
	replace_program(ROOM);
}

