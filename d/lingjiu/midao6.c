
inherit ROOM;

void create()
{
	set("short", "�ܵ�");
	set("long", @LONG
���������ţ�ͻȻ��������ʧ�˷����������ߵ�ʱ��ȴ�������Ѳ�
�������ĵ�·�ˣ��㲻������һ���顣ͻȻ���ڻ�Ƶĵƹ��£���Լ��
�����ߵĺ�����ǽ���Ͽ���һЩ���ι�״�ķ���(fuhao)��
LONG
	);
        set("item_desc",([
                        "fuhao" : "
��ʯ��������̹�����ŵľ������չ��书�ĵá�
\n"]));
	set("exits", ([
		"south" : __DIR__"midao5",
		"north" : __DIR__"midao7",
		"east" : __DIR__"midao13",
		"west" : __DIR__"midao14",
	]));
	setup();
}
#include "/d/lingjiu/midao.h"