//Cracked by Kafei
// wizlist.c
// by rider 7-12-01

#include <ansi.h>
inherit F_CLEAN_UP;
string blank_string = "                                    ";
string tribar_graph(int a);
int main(object me, string arg)
{
	string *list, name, class1, class2, class3, class4;
	mapping wizstatus, renwus;
	object user;
	int a = 0, b = 0, c = 0;
	int i, j;

	write(MUD_NAME + "Ŀǰ����ʦ�У�");

	renwus = SECURITY_D->query_wiz_renwu();
	list = keys(renwus);
	class1 = "";
	class2 = "";
	class3 = "";
	class4 = "";
	for( i=0; i<sizeof(list); i++)
	{
		j = strlen(renwus[list[i]]) - 1;
		if( !objectp(user=find_player(list[i])))
			name = WHT+list[i]+NOR;
		else if(user->query("env/invisibility"))
			name = HIY+list[i]+NOR;
		else name = HIG+list[i]+NOR;
		if( explode(renwus[list[i]],"\*")[0] == "GLB" )
		{
			a++;
			class1 += (a%2?"\n":"") + name +"("+YEL+explode(renwus[list[i]],"\*")[1]+NOR+")"+tribar_graph(j);
			}
		if( explode(renwus[list[i]],"\*")[0] == "KFB" )
		{
			b++;
			class2 += (b%2?"\n":"") + name +"("+YEL+explode(renwus[list[i]],"\*")[1]+NOR+")"+tribar_graph(j);
			}			
		if( explode(renwus[list[i]],"\*")[0] == "SWB" )
		{
			c++;
			class3 += (c%2?"\n":"") + name +"("+YEL+explode(renwus[list[i]],"\*")[1]+NOR+")"+tribar_graph(j);
			}
	}
write(HIY"\n"NOR"����������������������������"HBRED" ���� "NOR+"������������������������������"HIY"\n"NOR);
write(class1 + "\n");
write(HIY"\n"NOR"����������������������������"HBMAG" ������ "NOR+"������������������������������"HIY"\n"NOR);
write(class2 + "\n");
write(HIY"\n"NOR"����������������������������"HBCYN" ��Ҳ� "NOR+"������������������������������"HIY"\n"NOR);
write(class3 + "\n");
write(HIY"\n"NOR"������������������������������������������������������������������"HIY"\n"NOR);
write(CYN"�������ɸ���ά�����򣬿���������ÿ��һ��Сʱ�ռ� BUG ���ϣ�\n��Ҳ�����������Ҷ���Ϸ�Ľ����������\n"NOR);
write("����"HIG"����ɫ"NOR"�ı�ʾ���ߡ�\n\n\n");

return 1;

}
string tribar_graph(int a)
{
	return blank_string[0..(30-a)] + NOR;
}
int help(object me)
{
write(@HELP
ָ���ʽ : wizlist

��; : �г�Ŀǰ���е���ʦ������
HELP
     );
     return 1;
}								