// Code of ShenZhou
// Room: /d/dali/ziliu2.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���������̧ͷӭ���ȿ���һ�����ң�����д���������ʯ��,
�ӱʼ���,�ƺ����Դ�������������ֱʡ���������������̴��
��,�����ֲ��ŷ��Ű�����ľ�Ρ������򲢲�����,�ɼ�������Ϊ
������
LONG
        );
        set("cost", 1);
        set("wangfu", 1);

        set("exits", ([ /* sizeof() == 1 */
                "east" : __DIR__"ziliu1.c",
                ]));
        set("objects", ([
                "/kungfu/class/dali/zhu.c" : 1,
                ]));
     

        set("no_clean_up", 0);

        setup();
}
