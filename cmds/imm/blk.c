// Code of ShenZhou
// blkbot.c

inherit F_CLEAN_UP;
#define SYNTAX	"ָ���ʽ��blk <ʹ��������> because <ԭ��>\n"

int main(object me, string str)
{
	object ob;
	string name, reason;
	int i;
        if (!str) return notify_fail(SYNTAX);

	if( sscanf(str, "%s because %s", name, reason)!=2 )
		return notify_fail(SYNTAX);

	ob = LOGIN_D->find_body(name);
	if (!ob) return notify_fail("��... ���������?\n");
	// moving
	tell_room(environment(ob),"��������һֻ���ְ�"+
	(string)ob->query("name")+"ץ������, Ȼ�᲻����.\n", ob);
	tell_object(ob,"һֻ�ְ���ץ������, ����ǰһ���....\n");
	ob->move("/d/death/blkbot");
        tell_object(me, "���"+(string)ob->query("name")+"����շ��䡣\n");
	tell_object(ob,".... ����ʱ������"+(string)me->query("name")+
	"����Ū������.\n");
	tell_room(environment(ob),(string)ob->query("name")+"ͻȻ����"+
	"������ǰ\n",({me,ob}));
	// ok ..
	log_file("static/BLK", sprintf("[%s]%s(%s)��Ϊ%s��%s(%s)�ͽ��շ��䡣\n",
                ctime(time())[0..15], ob->name(), geteuid(ob),reason, me->name(), geteuid(me)));
	return 1;
}

int help(object me)
{
write(@HELP
ָ���ʽ : blk <ĳ��> because <ԭ��>

��ָ�������(��)��ĳ�˹ص��շ�����ȥ��
HELP
    );

    return 1;
}
