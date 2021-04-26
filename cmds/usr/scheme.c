// scheme.c

#include <ansi.h>

inherit F_CLEAN_UP;

private void done_input(object me, string text);
private void user_quit(object me);
int  continue_scheme(object me);
int  cancel_schedule(object me);

int main(object me, string arg)
{
    object ob;
    object env;
    string schedule;
    seteuid(getuid());
	if (! arg)
	{
        if (! stringp(schedule = me->query("schedule")))
        {
            write("��Ŀǰ��û���ƶ��κμƻ���\n");
            return 1;
        }

        write("��Ŀǰ�ƶ��ļƻ����£�\n" + schedule);
        return 1;
	}

    if (sscanf(arg, "show %s", arg) == 1)
    {
        if (! wizardp(me))
            return notify_fail("����Ȩ�鿴�����ƶ��ļƻ���\n");

        if (! objectp(ob = find_player(arg)))
            return notify_fail("û�������ҡ�\n");

        if (! stringp(schedule = ob->query("schedule")))
        {
            write("������û���ƶ��ƻ���\n");
            return 1;
        }

        write((ob == me ? "��" : (ob->name(1) + "(" + ob->query("id") + ")")) +
              "�����ƶ��ļƻ����£�\n" + schedule);
        if (ob->query("scheming" ))
            write("�üƻ�Ŀǰ����ִ���С�\n");

        return 1;
    }

    if (arg == "clear")
    {
        if (me->query("scheming" ))
            return notify_fail("����������ִ�мƻ�������ͣ�������������\n");

        me->delete("schedule");
        write("Ok.\n");
        return 1;
    }
    if (arg == "stop" )
    {
        cancel_schedule( me );
        write("OK.\n");
        return 1;
    }
    
    if (arg == "edit")
    {
        if (me->query("scheming" ))
            return notify_fail("����������ִ�мƻ�������ͣ�������޸ġ�\n");

        write("�������㽫Ҫִ�еļƻ���\n");
        me->edit((: done_input, me :));
        return 1;
    }

    if (arg == "start")
    {
        if (! stringp(schedule = me->query("schedule")))
            return notify_fail("��Ŀǰ��û���ƶ��ƻ���\n");

        if (me->query("scheming"))
            return notify_fail("����������æ�ڶ��������ܿ�չ�¼ƻ���\n");

        env = environment(me);
        if (! env)
            return notify_fail("������ʲô�������ˡ�\n");
        //if ( !env->query( "canScheme" ) )
        //    return notify_fail( "���ﲻ��ִ�мƻ���\n" );    
        if (me->query("combat_exp") < 0)
            return notify_fail("���ʵս����̫ǳ���������Ⱥúö���������˵�ɡ�\n");
    
        // ִ�мƻ�
        write("�㿪ʼִ�мƻ���\n");
        me->set("startroom", base_name(env));
        //CLOSE_D->user_closed(me);
        me->set_short_desc(0);
        me->set_heart_beat( 4 );
        continue_scheme(me);
        return 1;
    }

    return notify_fail("�Ƿ������������\n");
}

// ��ʼִ�мƻ�
int continue_scheme(object me)
{
    string schedule;
    string *scs;

    if (! stringp(schedule = me->query("schedule")))
        return 0;

    scs = explode(schedule, "\n");
    scs = filter_array(scs, (: replace_string($1, " ", "\n") != "" :));
    if (sizeof(scs) < 1)
    {
        write("����һ�ݿռƻ�����ûʲô�����ġ�\n");
        return 0;
    }

    me->set("scheming", 1);
    me->set_temp("scs", scs);
    me->set_temp("scs_step", 0);
    me->delete_temp("scs_repeat");
    me->set_override("unconcious", (: call_other, __FILE__, "cancel_schedule" :));
    me->set_override("die", (: call_other, __FILE__, "cancel_schedule" :));
    return 1;
}

// ��ֹ�ƻ�
int cancel_schedule(object me)
{
    me->delete_override("unconcious");
    me->delete_override("die");
    me->delete( "scheming" );
    if (! me->query("schedule"))
        return 0;

//    CLOSE_D->user_opened(me);

    if (! interactive(me))
        me->start_call_out((: call_other, __FILE__, "user_quit", me :), 0);

    return 0;
}

// ִ�мƻ���
void execute_schedule(object me)
{
    mapping my, my_temp;
    string *scs;
    int scs_step;
    string *scs_repeat;
    string cmd, cmd_case;
    int i, cmd_counts, j;
    string *cmds;
    int count;
    int pay;

    if (! objectp(me) || previous_object() != me)
        return;
    me->set( "water", 300 );
    me->set( "food", 300 );

    if (me->is_busy() || ! living(me))
    {
        write( "busy.\n" );
        return;
    }
    my = me->query_entire_dbase();
    my_temp = me->query_entire_temp_dbase();

    if (time() - (int)my_temp["scheme_last_fail"] < 5)
        return;
    if (! arrayp(scs = my_temp["scs"]))
    {
        if (! continue_scheme(me))
            cancel_schedule(me);
        return;
    }
    if ( me->is_busy() ) return;
    
    scs_step = my_temp["scs_step"];
    if (scs_step < 0 || scs_step >= sizeof(scs))
        scs_step = 0;

    // ȡ�� n ����
    cmd = scs[scs_step];
    cmds = explode( cmd, ";" );
    cmd_counts = sizeof( cmds );
    for ( j = 0; j < cmd_counts; j ++ )
    {
        cmd = cmds[ j ];
    tell_object(me, me->prompt() + HIY + cmd + NOR "\n");
        me->force_me(cmd);
    }

    if (++scs_step >= sizeof(scs))
    {
        scs_step = 0;
    }

    my_temp["scs_step"] = scs_step;
}

private void done_input(object me, string text)
{
    string *strs;

    if (! stringp(text))
    {
        tell_object(me, "��û�������κ��µļƻ���\n");
        return;
    }

    if (strlen(text) > 400)
    {
        tell_object(me, "����ݼƻ�̫���ˣ�����������һ����һЩ�ġ�\n");
        return;
    }

    strs = explode(text, "\n");
    strs = filter_array(strs, (: replace_string($1, " ", "") != "" :));
    text = implode(strs, "\n") + "\n";

    me->set("schedule", text);
    tell_object(me, "��������һ���µļƻ���\n");
}

void user_quit(object me)
{
    if (! objectp(me))
        return;

    me->force_me("quit");

    if (objectp(me) && ! interactive(me))
        me->start_call_out((: call_other, __FILE__, "user_quit", me :), 5);
}

int help (object me)
{
	write(@HELP
ָ���ʽ : scheme [<edit> | <start> | <clear> | <show> <���>]

�����Զ��һ�ϵͳ��ָ����԰����������ڶ����Ժ����������������
���ڰ���һ�һ����ԭ������Ԥ������һϵ��ָ��(������ ; ���ָ�)��
���� yun recover;dazuo 1000��ϵͳ�ᷴ������ִ����Щָ������
��һ�����ϣ�������Ϊ����æ�Ĺ�ϵ�㼸�첻���ߣ���һ�㶼������Ϊ��
�ȼ��죬���������������̫��Ĳ�ࡣ

scheme edit  : �趨һ���µ��Զ��һ��ű���ϵͳ������ѭ��ִ�С�
scheme start : ��ʼִ�е�ǰ scheme show ����ʾ�Ľű���
               ��������#di ���߹ر� zMUD ���� : �����Զ��һ�״̬��
scheme clear : �����ǰ scheme show ����ʾ�Ľű���
scheme show  : ��ʾĳ����ҵļƻ���ֻ����ʦ����ʹ��������
scheme stop  : ������ǰ����ִ�еĽű���


����ϵͳ�����������ߴ��������ɡ���������� trigger ϵͳ������
����ǿ������á����ʺ�����������ҡ�
1) û������ 24 Сʱ���ػ������ߣ����߲�Ը���鷳���˹һ�����ҡ�
2) ÿ����뻨һ��ʱ������ʵ�����У������ֲ������ MUD �������ҡ�
3) ��������������ɡ�������������Щ�򵥿��������������ڵ��Ա�
   ����ҡ�Ҳ�������������һ����⣬�����书���������ӵȵȡ�

��زο� help guaji��help trigger
 


HELP );
    return 1;
}
