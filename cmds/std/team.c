// Code of ShenZhou
// team.c
//
// Zhuang@XKX 960831
//
// Implementation Notes:
//
// To start a team, `team invite sb`, then you become the team leader.
// To join a team, after the team leader invites you, `team join leader`.
// If you are a leader, `team dismiss` disbands the team, `team dismiss memeber`
// kicks out the member.
// If you are not a leader, `team dismiss` makes you leave the team.
// When a team leader quits or dies, the second most senior member
// automatically becomes the new leader.
// As a team leader, if you accepts someone's invitation, you will bring the
// whole team to the new leadership.
//

#include <command.h>
#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object *t;
return 1;

	if( !arg ) {
		if( !pointerp(t = me->query_team()) )
			return notify_fail("�����ڲ�û�вμ��κζ��顣\n");
		write("�����ڶ����еĳ�Ա�У�\n  " + implode(t->name(1), "\n  ") + "��\n");
		return 1;
	}
	if( arg=="dismiss" ) {
		if( !pointerp(t = me->query_team()) )
			return notify_fail("�����ڲ�û�вμ��κζ��顣\n");
		if( me->is_team_leader() ) {
			message("team", HIG "�����顿" + me->name(1) + "�������ɢ�ˡ�\n" NOR, t, me);
			write(HIG "�㽫�����ɢ�ˡ�\n" NOR);
		} else {
			message("team", HIG "�����顿" + me->name(1) + "����������顣\n" NOR, t, me);
			write(HIG "����������Ķ��顣\n" NOR);
		}
		me->dismiss_team();
		return 1;
	}
	if( sscanf(arg, "dismiss %s", arg)==1 ) {
		object ob;

		if( !pointerp(t = me->query_team()) || !me->is_team_leader() )
			return notify_fail("ֻ�ж���������Կ�����Ա��\n");

        if( !(ob = find_living(arg))
        ||  !ob->is_character()
        ||  ob==me
		||  !me->have_team_member(ob) )
			return notify_fail("���뿪��˭��\n");

		message("team", HIG "�����顿" + me->name(1) + "��" + ob->name(1) + "�����ˡ�\n" NOR, t, me);
		write(HIG "�㽫" + ob->name(1) + "��������Ķ��顣\n" NOR);
		me->dismiss_team(ob);
		return 1;
	}
	if( sscanf(arg, "fight %s", arg)==1 ) {
		if( !pointerp(t = me->query_team()) || !me->is_team_leader() )
			return notify_fail("ֻ�ж���������Է�����ս����\n");

		for( int i = 0; i < sizeof(t); i++ )
			if( living(t[i]) )
				KILL_CMD->main(t[i], arg);
		return 1;
    }
	if( sscanf(arg, "invite %s", arg)==1 ) {
		object ob;

		if( pointerp(me->query_team()) && !me->is_team_leader() )
			return notify_fail("ֻ�ж����������������˼��롣\n");

		if( !(ob = present(arg, environment(me)))
		||	!living(ob)
		||	!ob->is_character()
		||	ob==me )
			return notify_fail("��������˭���룿\n");

		if( me->have_team_member(ob) )
			return notify_fail(ob->name(1) + "�Ѿ�����Ķ����Ա�ˡ�\n");

		message_vision("$N����$n����$P�Ķ��顣\n", me, ob);
		tell_object(ob, YEL "�����Ը����룬���� team join " + me->query("id") + "��\n" NOR);
		me->set_temp("pending/team", ob);
		return 1;
	}
	if( sscanf(arg, "join %s", arg)==1 ) {
		object ob;

        if( !(ob = present(arg, environment(me)))
        ||  !living(ob)
        ||  !ob->is_character()
        ||  ob == me
		||  me != (object)ob->query_temp("pending/team") )
            return notify_fail("�������˭�Ķ��飿\n");

		if( pointerp(t = me->query_team()) && !me->is_team_leader() )
			return notify_fail("���Ѿ���һ���������ˡ�\n");

		if( !pointerp(t) ) {
			ob->add_team_member(me);
			message_vision("$N��������$n�Ķ��顣\n", me, ob);
			message("team", HIG "�����顿" + me->name(1) + "����" + ob->name(1) + "�Ķ��顣\n" NOR, me->query_team());
		} else {
			me->join_team(ob);
			message_vision("$N��������$n�Ķ��顣\n", me, ob);
			message("team", HIG "�����顿" + implode(t->name(1), "��") + "����" + ob->name(1) + "�Ķ��顣\n" NOR, me->query_team());
		}
		ob->delete_temp("pending/team");
		return 1;
	}
	if( sscanf(arg, "talk %s", arg)==1 ) {
		if( !pointerp(t = me->query_team()) )
			return notify_fail("�����ڲ�û�кͱ�����ɶ��顣\n");
		message("team", HIW "�����顿" + me->name(1) + "(" + capitalize(me->query("id")) + ")" + "��" + arg + "\n" NOR, t);
		return 1;
	}
	if( sscanf(arg, "talk* %s", arg)==1 ) {
		string vb, emote_arg;
		
		if( !pointerp(t = me->query_team()) )
			return notify_fail("�����ڲ�û�кͱ�����ɶ��顣\n");
                        
		if( sscanf(arg, "%s %s", vb, emote_arg) != 2 ) {
			vb = arg;
			emote_arg = "";
		}
		arg = EMOTE_D->do_emote(me, vb, emote_arg, 1);
		if( !arg ) arg = me->name()+vb+" "+emote_arg+"\n"; 
		message("team", HIW "�����顿" + arg + NOR, t);
		
		return 1;
	}	
	if( sscanf(arg, "form %s", arg)==1 ) {
		if( !pointerp(t=me->query_team()) || !me->is_team_leader() )
			return notify_fail("�������һ����������������֯���Ρ�\n");
		if( !me->query_skill(arg, 1) )
			return notify_fail("����������ûѧ����\n");
		return SKILL_D(arg)->form_array(me);
	}
}

int help(object me)
{
	write(@HELP
����ָ��ʹ�÷���:

team invite <ĳ��>  - ����ĳ�˼�����Ķ��顣������Ƕ�������������κζ��顣
team join <ĳ��>    - ����ĳ�˵Ķ��顣��������ܵ����롣������Ƕ������䣬���
                      ����ȫ�Ӽ��롣
team dismiss        - �뿪���顣���´�ָ��������䣬������������ɢ��
team dismiss <ĳ��> - ��ĳ�˿������ӡ�������Ƕ������䡣
team fight <ĳ��>   - ���幥��ĳ�ˣ������� tf <ĳ��> �����������Ƕ������䡣
team talk <ѶϢ>    - ����������������̸��, ������ tt <ѶϢ> �����
team form <��>    - �����������ѧ���󷨵Ļ������Խ������еĳ�Ա��֯��
                      ĳ�����Σ�������ε�״ֻ̬Ҫ����һ�ƶ��ͻ�����

ֱ���� team ָ��ʱ�����ʾ��Ŀǰ�Ƿ��м�����鼰��Ա������

ע: team �� follow �Ƕ����ģ��㲻һ��Ҫ follow ��������䡣
HELP
	);
	return 1;
}
