// outdoor.c zip@hero 2000.1.27 �����ſ�
#include <ansi.h>
#define ID 5801
inherit ROOM;
void create()
{	string *dir=({"��","��"});
	set("short",HIG"���ݴ��"+chinese_number(ID/100)+"��"+dir[ID%2]+NOR);
	set("long",@LONG
��������ǧ��(poop)��[1;36m���ľ�[37;0m��
    ���˴�뱲�ӣ������������ˣ����������
LONG	);
	set("exits",([
	"east" : __DIR__"street"+(string)(ID/100),
	]));
	set("owner","poop");
	set("coor/x",40+(ID%2)*20);
	set("coor/y",20+(ID/100)*10);
	set("coor/z",0);
	setup();
}
#include "outdoor_func.c"