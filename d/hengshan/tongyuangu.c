//Cracked by Roath
#include <room.h>
inherit ROOM;
void create()
{
        set("short", "ͨԪ��");
        set("long", 
"ͨԪ��λ�ڼ��Է��£��ഫ��ʱ�����Ź������ڴ����������д�ʯ
������ӡ�����������ഫΪ�Ź�������¿��̤���������ڷ��Ź���Ϊ��
ͨԪ��������ͨԪ��֮�������ɴ˶������ɹ����������Է壬��ɫ��ң
ң�ɼ���
\n"
        );
        set("exits", ([
                "eastup"  : __DIR__"guolaoling",
]));
        set("no_clean_up", 0);
        set("outdoors", "hengshan");	
        set("cost", 1);	
        setup();
        replace_program(ROOM);
}

