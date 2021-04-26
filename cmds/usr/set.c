// Code of ShenZhou
// set.c
 
#include <ansi.h>
#define MAX_ENV_VARS	20
 
inherit F_CLEAN_UP;
 
int help();
 
int main(object me, string arg)
{
    int i;
    string term, *terms, *wiz_only;
	mixed data;
	mapping env;
 
    wiz_only = ({"invisibility", "immortal"});
 
	if( me != this_player(1) ) return 0;
 
	env = me->query("env");
 
	if( !arg || arg=="" ) {
		write("��Ŀǰ�趨�Ļ��������У�\n");
		if( !mapp(env) || !sizeof(env) )
			write("\tû���趨�κλ���������\n");
		else {
			terms = keys(env);
			for(i=0; i<sizeof(terms); i++)
				printf("%-20s  %O\n", terms[i], env[terms[i]]);
		}
		return 1;
	}
 
	if( sscanf(arg, "%s %s", term, data)!=2 ) {
		term = arg;
		data = "YES";
	}

        data = replace_string(data, "$BLK$", BLK);
        data = replace_string(data, "$RED$", RED);
        data = replace_string(data, "$GRN$", GRN);
        data = replace_string(data, "$YEL$", YEL);
        data = replace_string(data, "$BLU$", BLU);
        data = replace_string(data, "$MAG$", MAG);
        data = replace_string(data, "$CYN$", CYN);
        data = replace_string(data, "$WHT$", WHT);
        data = replace_string(data, "$HIR$", HIR);
        data = replace_string(data, "$HIG$", HIG);
        data = replace_string(data, "$HIY$", HIY);
        data = replace_string(data, "$HIB$", HIB);
        data = replace_string(data, "$HIM$", HIM);
        data = replace_string(data, "$HIC$", HIC);
        data = replace_string(data, "$HIW$", HIW);
        data = replace_string(data, "$NOR$", NOR);
        term = replace_string(term, "/", "");

	if( term && term!="" ) {
		if( mapp(env) && undefinedp(env[term]) && sizeof(env) >= MAX_ENV_VARS )
			return notify_fail("����Ļ�������̫���ˣ������� unset ɾ�������ɡ�\n");
		sscanf(data, "%d", data);
        if((wiz_level(me) == 0) && (member_array(term, wiz_only) != -1))
            return notify_fail("ֻ��������������趨��\n");
        me->set("env/" + term, data);
		printf("�趨����������%s = %O\n", term, data);
		return 1;
	}
	return help();
}
 
int help()
{
	write(@TEXT
ָ���ʽ��set <������> [<����ֵ>]
 
���ָ�������趨һЩ�������������Ӳ���ʱ����ʾ��Ŀǰ�趨�Ļ�����������ָ��
����ֵ�����ڶ�ֵΪ "YES"��
 
ȡ�������趨���� unset ָ�
 
�������Щ�������������趨����� help settings��
TEXT
	);
	return 1;
}
