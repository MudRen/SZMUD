//room: /newjob/builder/tsshiwu.c ̩ɽʯ��
//Lara 2001/12/09
inherit ROOM;
#include <ansi.h>
void create()
{
        set("short", "ʯ��");
        set("long", @LONG
һ�䲻���۵�С�ݣ���������ȫ����ʯͷ���ɡ�����������˻ҳ���
�����þ�û�˾�ס�ˡ�������һЩ���õĶ�����������ĳ�ֹ��ߣ�������
������ʲô�ó��ġ���˵���������⿴����һ�����ص����ˡ�
LONG
        );

        set("exits", ([        
        "west" : __DIR__"tshgslu",
        ]));
        set("no_clean_up", 0);        
        set("invalid_startroom", 1);       
        set("cost", 1);
        setup();
}
