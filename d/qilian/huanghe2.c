// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "�ƺ�");
        set("long", @LONG
��ˮ���˹��ˣ���Դ�ھ�Ȫ�����ĺ�ˮ�����³Ǻ��������������
ˮ��ȥ���𽥼�ǿ��Ю����ǧ��ֵĸ�ԭ��ɳ���Ʋ��ɵ��������ϱ�ȥ��
���ڴ˴�ˮ���ļ���������������֬�ᡣ�������µĻƺӴ����㼴��
�ڴˡ�
LONG
        );
        set("exits", ([
                "east" : __DIR__"huanghe1",
                "west" : __DIR__"yongdeng",
        ]));


	set("cost", 2);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
