//Modify by Karlopex@sz
#include <ansi.h>
int help(object me);
void create()
{
        seteuid(getuid());
}

int main(object me, string arg)
{
	int addvalue;
	object ob, ob2;
	string strID, outmsg, strRes, strID2, msgvalue;

        if( !arg || arg == "") return help(me);

	if( sscanf(arg, "%s to %s %s", strID, strID2, msgvalue) !=3
	    && sscanf(arg, "%s %s %s", strID, msgvalue, strRes) !=3 )
		return help(me);
        addvalue = atoi(msgvalue);
        ob = find_player(strID);

	if ( !objectp( ob ) ) return notify_fail( "No such guy online.\n" );

	if ( stringp(strID2) ){
		ob2 = find_player(strID2);
		if (!objectp( ob2 )) return notify_fail( "No such guy online.\n" );
		if ( ob->query("shenzhou/pts") < addvalue )
			return notify_fail( ob->query("id")+"'s Gxd no enough.\n" );
		if ( addvalue%100 != 0 )
			return notify_fail( "���׶�ת��ֻ���԰�Ϊ��λ��\n" );
		}

	if ( !this_player()->visible( ob ) && strID == "mariner" )
		return notify_fail( "No such guy online.\n" );

	if (!objectp( ob2 )){
		outmsg = sprintf("%s(%s) ��Ϊ %s ������ %s(%s) %s �㹱�׶�", me->query("name"), getuid(me), strRes, ob->query("name"), getuid(ob), chinese_number(addvalue)); 
		log_file("awards/gxadd",sprintf("[%s]  %s(%s) ��Ϊ %s ������ %s(%s) %s �㹱�׶ȡ�\n",
			ctime(time())[0..15], me->query("name"), getuid(me), strRes, ob->query("name"), getuid(ob), chinese_number(addvalue))); 
        	ob->add("shenzhou/pts", addvalue);
		tell_object(ob, HIG"��Ĺ��׶������� "+chinese_number(addvalue)+" �㡣\n");
	}else{
		outmsg = sprintf("%s(%s) �� %s(%s) �� %s �㹱�׶�ת�� %s(%s) ", me->query("name"), getuid(me), ob->query("name"), getuid(ob), chinese_number(addvalue), ob2->query("name"), getuid(ob2));
		log_file("awards/gxadd",sprintf("[%s]  %s(%s) �� %s(%s) �� %s �㹱�׶�ת�� %s(%s)��\n ",
			ctime(time())[0..15], me->query("name"), getuid(me), ob->query("name"), getuid(ob), chinese_number(addvalue), ob2->query("name"), getuid(ob2))); 
	        ob->add("shenzhou/pts", -addvalue);
	        ob2->add("shenzhou/pts", addvalue);
		tell_object(ob, HIG"��� "+chinese_number(addvalue)+" �㹱�׶��Ѿ�ת�Ƹ�"+ob2->name()+" ��\n");
		tell_object(ob2, HIG+ob2->name()+"�� "+chinese_number(addvalue)+" �㹱�׶��Ѿ�ת�Ƹ��� ��\n");
	}
        shout( HIG "��ϵͳ�����棺" + outmsg + "\n" NOR );
        write( HIG "��ϵͳ�����棺" + outmsg + "\n" NOR );
        return 1;
}
int help(object me)
{
        write(@HELP
ָ���ʽ : addgx <��������> <���׶�����> <ԭ��>
           addgx <��������1> to <��������2> <���׶�����>

see also : checkgx
HELP
    );
    return 1;
}