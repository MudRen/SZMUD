//CODE BY SCATTER
//Control Center
//ccenter.c

#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", "����ϵͳ������");
        set("long", @LONG
������Ǵ�˵�еĿ�����. ��Ȼ���￴��������
��������Ĺ��ܶൽ��������. ��Ȼ����㿴��
�κ�����, ���ʷ�ڤ�ӻ������ʦ. ���ϵͳ��
�����ݵĺ���֮һ. �����м��Ҹ��趨. �ȸ���
��˵��лл��.
LONG
        );


        set("exits", ([
                "familyjob" : "/family_job/control.c",
                                        "out" : "/d/wizard/meeting_room",
                                        "wudang" : "/menpai_job/wudang/wudang.c",
        ]));

        set("cost", 1);
        setup();
        replace_program(ROOM);
}
