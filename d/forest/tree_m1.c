// Code of ShenZhou
// Jay 7/9/96

#include "tree.h"
 
void create()
{
    int i;
        set("short", "����");
        set("long", @LONG
����֦��Ҷï�������ϳ�����̦����Ҷ������Щ�ж������棬����
���ղ����ĵط��䶯���ּ���ָ���������ڻ����������һЩ������
���ϵĶ����ϴ�����������ҵ�����������
LONG
        );

/*	set("objects", ([
		__DIR__"npc/mulang" : 1,
	]));
*/

	set("climbright",__DIR__"tree_m2");
	set("climbdown", __DIR__"middle");

	set("cost", 3);
        setup();
}

