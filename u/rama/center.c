/* /kungfu/class/movie/center.c
** ���ݵ�ӰԺ
** created by yujie
** created in 11/2001
*/

inherit ROOM;

void create()
{
        set("short", "��ӰԺ");
        set("long", @LONG
���������ݵĵ�ӰԺ���ܶྭ��ġ����µĵ�Ӱ���ᾭ�����š�����
���ȥ���Ե���ӰԺ�Ĵ��������ߵ�ͨ���ֱ�ͨ��һЩ���ǵ�ר��������
�������ɵ�Ƭ���ţ�������Ӱ�Ծ��ֲ������������Ӱ�����Ϻ����¶�̬
���Բ�ѯ�������Ժȱ������������Լ�ϲ�������Ǻ͵�Ӱ���Ӿ硣
LONG
        );

        set("exits", ([
                "out" : "/d/city/guangchang",
                "enter" : __DIR__"mainroom",
                "takako" : __DIR__"takako1",
                "down" : __DIR__"talkroom",
        ]));

        set("objects", ([
                "/kungfu/class/movie/npc/waiter" : 1,
                "/kungfu/class/movie/obj/pub_b" : 1,
        ]));

        set("cost", 0);
        setup();
      call_other("/clone/board/movie_b", "???");
}
