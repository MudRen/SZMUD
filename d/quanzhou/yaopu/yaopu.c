// Code of ShenZhou

inherit ROOM;

void create()
{
	set("short", "�������ϵ�");
	set("long", @LONG
���Ǽ����ֺŵ���ҩ�̣�����������Ũ���ҩζ����ǰ����һ����
���̨����̨����һ��˶���ޱȵ�ҩ�񣬼�����ס������ǽ����������
������ʢҩ��С���룬ÿ�����������С�֣�ע��ҩ�����ơ�
LONG
	);
	set("exits", ([ 
 	"north" : "__DIR__citong_w2",
 	"east" : __DIR__ "yaofang",
 	"enter" : __DIR__ "neitang",
]));
    set("objects", ([
         __DIR__"npc/wang" : 1,
]));
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);	
}
