 // Code by Scatter
// �ڷ���
// gate.c
#define SAVE_NPC "/family_job/savenpc"
inherit ROOM;

void create()
{
set("short", "�ڷ��¶�");
        set("long", @LONG
������Ǵ�˵�еĺڷ��µ�ɽ�š������������ϸо���������ޱȵ�������
�Լ�һ��˵��������а����������һ������д�������� - ɱ���� - ͻȻ��
�����Ѿ�û����·�ˣ�ֻ�к���ɱ���ڷ��µĺڷ�����ܻص���ԭ��������
һ��������ֿ�����ɽ���������֪����ɽ��·һ�������ߡ�
(BETA ���԰�V9.0 ������� NPC ��ɱ����, ��� complete)
LONG );

        set("exits", ([
                "southdown"  : __DIR__"hill17",
        ]));

        setup();
        //replace_program(ROOM);
}

void init()
{
        add_action("do_finish", "complete");
}

int do_finish(string arg)
{
        object me=this_player();
        string fname, pdata, ropen;
        int maxkillnum, killnum;

        fname = "fjob/mp/killnum";
        ropen = SAVE_NPC->do_load(fname);
        killnum = atoi(ropen);

        fname = "fjob/mp/maxkillnum";
        ropen = SAVE_NPC->do_load(fname);
        maxkillnum = atoi(ropen);

        if(maxkillnum != killnum)
        {
                write("��ĵ����и���������û����ɣ�\n");
                return 1;
        }

        write("\n��л����Զ��˺���ģʽ FAMILY_JOB BETA V9.0 (���Ȳ��԰�)\n���� 2000 �㾭��ֱ�Լ�Ǳ��ȫ��\n");
        me->add("combat_exp", 2000);
        me->set("potential", me->query("max_potential"));
        me->move(me->query_temp("family_job/rplace"));
        return 1;
}
