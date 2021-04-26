// Code of ShenZhou
// Room: /d/dali/taihec.c

inherit ROOM;

void create()
{
	set("short", "̫�ͳ�");
	set("long", @LONG
�˳�����������θ���ȫ����İ����ʯ�ݳɣ������࣬�������ﲻ�ϡ�̫��
�����ǣ����˿�Ϊ�������٣������Ϻ;������Ǵ���ǵı��Ż�������������
�����ڴ˼ӹ̳ǳأ���פ������������һЩ���Ĳ���۾ӡ�������һƬƽԭ����
ʮ���������ǡ�
LONG);
	set("objects", ([
		__DIR__"npc/dalishibing.c" : 2,
		__DIR__"npc/wujiang.c" : 1,
		]));
	set("exits", ([
		"north" : __DIR__"nanbei",
		"south" : __DIR__"gaten1",
		]));
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
