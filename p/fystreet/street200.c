// outdoor.c zip@hero 2000.1.27 �����ſ�
#include <ansi.h>
#define ID 200
inherit ROOM;
void create()
{	string *dir=({"��","��"});
	set("short",HIG"���ݴ��"+chinese_number(ID/100)+"��"+dir[ID%2]+NOR);
	set("long",@LONG
����������(chat)��[1;32m����ׯ[37;0m��
    �����Ǵ�˵�е���Ѫ����ͷ�ϴ����ĵľ�����
LONG	);
	set("exits",([
	"west" : __DIR__"street"+(string)(ID/100),
	]));
	set("owner","chat");
	set("coor/x",40+(ID%2)*20);
	set("coor/y",20+(ID/100)*10);
	set("coor/z",0);
	setup();
}
#include "outdoor_func.c"