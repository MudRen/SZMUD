// Code of ShenZhou
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "̫�ͳ�");
	set("long", @LONG
�˳�����������θ���ȫ����İ����ʯ�ݳɣ������࣬��������
���ϡ�̫�Ͳ����ǣ����˿�Ϊ�������٣������Ϻ;������Ǵ����
�ı��Ż������������������ڴ˼ӹ̳ǳأ���פ������������һЩ��
�Ĳ���۾ӡ�������һƬƽԭ����ʮ���������ǡ�
LONG
        );

	set("exits", ([
		"south" : __DIR__"gaten1",
		"north" : __DIR__"nanbei",
		]));

	set("objects", ([
		"/d/dali/npc/dalishibing.c" : 2,
		"/d/dali/npc/wujiang.c" : 1,
		]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}
