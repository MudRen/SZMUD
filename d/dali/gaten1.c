// Code of ShenZhou
// minority or tribe village
// acep

inherit ROOM;

void create()
{
	set("short", "����Ǳ�");
	set("long", @LONG
�����Ǹ���·�ڡ��ϱ߾��Ǵ���ǵı����ˣ���·������ֲ�
��ȥ�ɵ�̫�ͳǣ�����ͨ���¹سǣ�Ҳͨ��ɽ����ȥ�β�ɽ�ͳ�ʥ��
�ıؾ�֮·��
LONG
        );

	set("exits", ([
		"north" : __DIR__"taihec",
		"northwest" : __DIR__"esqiao",
		"south" : __DIR__"northgate",
		]));

	set("outdoors","dali");
	set("cost", 2);
	setup();
}
