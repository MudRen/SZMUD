// Code of ShenZhou
// Summer 9/12/96
#include "room.h"

inherit ROOM;

void create()
{
        set("short", "����ɽ");
        set("long", @LONG
��ɽ������������ݲ�����һ��̤��ɽ��, �ٸ�һ��Ī����״�Ĺ���֮
Ϣ����˵�е������������ɱ��ۣ�û�гɹ�����ۿ�������ͷ����������
Ϊ�죬˫��ΪĿ�������������ս��ʧ���ᱻ��춴�ɽ��
LONG
        );
        set("exits", ([
                "southeast" : __DIR__"tieshi",
                "southwest" : __DIR__"zibai",
        ]));


	set("cost", 3);
        setup();
        set("outdoors","qilian-shan");
        replace_program(ROOM);
}
