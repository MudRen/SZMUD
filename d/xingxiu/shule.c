// Code of ShenZhou
// shule.c ����
// maco 2/17/2000

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�����Ǻ���������ʮ����֮һ�����ͨʹ����ʱ����Զ�ﵽ�ˣ���
�������򶼻������������೬���ε����򣬾���������Ϊ��Ӫ��˿·
�ϱ�·�ڴ˽��ᣬ��ȥ���������ö��ڴ�פ����Ϣ�����Ҳ���Ļ�����
֮�أ��ż�����ʤ���Ļ��Ų���ʢ����Χ�İ�������Ũ�������������
LONG
	);
	set("exits", ([ 
	    "south" : __DIR__"caoyuan4",
	    "west" : __DIR__"qingzhensi",
	    "north" : __DIR__"huyang5",
	    "northeast" : __DIR__"baza1",
	]));
	set("objects", ([ 
	    "/d/xingxiu/npc/kid" : 1,
	    "/d/xingxiu/npc/w-girl" : 1,
	]) );
	set("outdoors","xingxiuhai");

	set("cost", 1);
	setup();
}
