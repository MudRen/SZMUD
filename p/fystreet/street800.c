// outdoor.c zip@hero 2000.1.27 �����ſ�
#include <ansi.h>
#define ID 800
inherit ROOM;
void create()
{	string *dir=({"��","��"});
	set("short",HIG"���ݴ��"+chinese_number(ID/100)+"��"+dir[ID%2]+NOR);
	set("long",@LONG
�����ǵ����Ե(fjss)��[1;37m����[1;32mɽׯ[37;0m��
    ��������ɽ���  һ������ˮ����
LONG	);
	set("exits",([
	"west" : __DIR__"street"+(string)(ID/100),
	]));
	set("owner","fjss");
	set("coor/x",40+(ID%2)*20);
	set("coor/y",20+(ID/100)*10);
	set("coor/z",0);
	setup();
}
#include "outdoor_func.c"