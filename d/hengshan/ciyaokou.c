//Cracked by Roath
#include <room.h>
inherit ROOM;

void create()
{
        set("short", "��Ҥ��");
        set("long", 
"��Ҥ��Ϊ��ɽ����������������֮�������Ҫ�����Թ���
��ȥ��������ţ������̴�����η�����εΪ׳�ۡ���Ҥ��λ��
Ͽ��֮�У���խ���������ɣ�����һ�ߣ��γɾ������գ��Թ�Ϊ
���ұ���Ҫ����\n");
        
set("exits", ([
                "westup"  : __DIR__"wusean",
                "eastup"   : __DIR__"xuankongsi",
        ]));
        set("no_clean_up", 0);
        set("outdoors", "hengshan");
        set("cost", 1);
        setup();
        replace_program(ROOM);
}

