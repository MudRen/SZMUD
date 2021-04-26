//Cracked by Roath
// Room: /d/beijing/shizilukou.c

inherit ROOM;

void fix_exits_for_night(int is_night)
{
    if (is_night) {
	set("exits", ([ 
  	"north" : __DIR__"zhengyangdajie",
	]));
    }else{
	set("exits", ([ 
  	"north" : __DIR__"zhengyangdajie",
	"south" : __DIR__"yonganmen",
	]));
    }
}

void create()
{
	set("short", "ʮ��·��");
	set("long", @LONG
����һ����ͨ��ʮ��·�ڣ�·������������������Χ��ЩС����
���۸�������ٻ���������Կ�����̳�����ĵ��������ɽ��
̳�������������ţ����������������֡�
LONG
	);
	fix_exits_for_night(0);
	
	set("objects", ([
	__DIR__"npc/miscseller":1,
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");
	set("cost", 2);
	setup();
}

