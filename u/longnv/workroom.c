// workroom.c Ľ�ݻ�
// maxking by 2002.09.03 
// Room: /u/maxking/workroom.c
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create() 
{
set("short",BLINK+HIW"ī�����"NOR);
set("long",
"����һ�������ûʵĴ�լԺ����ͷ�ߴ��ʯʨ����ס�˴��� 
���࣬�����ϵ��������������������һ���ң�����"CYN"��"NOR""NOR+BLINK+HIG"����"NOR""CYN"��"NOR"
�������֡�
\n");
set("valid_startroom",1);
set("exits", ([
"maxking": "/u/maxking/workroom",
"rabit": "/u/rabit/workroom",
"cs": "/d/city/guangchang"
]));
              call_other("/clone/board/longnv_b", "???"); 
setup();
}
