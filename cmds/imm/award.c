// Code of ShenZhou
// /cmds/wiz/award.c
// sdong, 1/1/99

inherit F_CLEAN_UP;
#include <ansi.h>

int main(object me, string arg)
{
		string id, type, value;
		object user, where;

		if (!arg) return notify_fail("ָ���ʽ��award <player id> type value\n");
		me = this_player();
		where = environment(me);

		  //if( wizhood(me) != "(arch)" && wizhood(me) != "(admin)" && wizhood(me) != "(wizard)"&& wizhood(me) != "(caretaker)" ) return 0;

		  if( sscanf(arg, "%s %s %s", id, type, value) != 3 )
				 notify_fail("ָ���ʽ��award <player id> type value.\n");

		  user = find_player(id);
		  if( !user )
		  {
			  seteuid("Root");
			  user = new(USER_OB);
			  user->set("id", id);
			  user->set("master_id", id);
			  if (!user->restore())
					 return notify_fail("û�������ҡ�\n");;

			  user->setup();
			  message_vision("$N���������������$n\n", me, user);
			}

			user->move(where);


		  if( type == "title" )
		  {
			  value = replace_string(value, "$BLK$", BLK);
			  value = replace_string(value, "$RED$", RED);
			  value = replace_string(value, "$GRN$", GRN);
			  value = replace_string(value, "$YEL$", YEL);
			  value = replace_string(value, "$BLU$", BLU);
			  value = replace_string(value, "$MAG$", MAG);
			  value = replace_string(value, "$CYN$", CYN);
			  value = replace_string(value, "$WHT$", WHT);
			  value = replace_string(value, "$HIR$", HIR);
			  value = replace_string(value, "$HIG$", HIG);
			  value = replace_string(value, "$HIY$", HIY);
			  value = replace_string(value, "$HIB$", HIB);
			  value = replace_string(value, "$HIM$", HIM);
			  value = replace_string(value, "$HIC$", HIC);
			  value = replace_string(value, "$HIW$", HIW);
			  value = replace_string(value, "$NOR$", NOR);
			  user->set("title",value);
			  message_vision(HIY"$N����$n˵������������ͷ��"+value+"����ϲ��ϲ�������͸�ѽ��\n"NOR,me,user);
		  }
		  else if( type == "9yin" )
		  {
				user->set("9yin",value);
				message_vision(HIY"$N����$n˵��������书��տ������Ȩ����Թ��������澭�ϵ��书��\n"NOR,me,user);
		  }
		  else return notify_fail("�������������.\n");

	 user->save();
    log_file("/static/AWARD_LOG", sprintf("%s %s(%s) award %s %s %s.\n", ctime(time()), geteuid(me), wizhood(me), id, type, value ) );

	return 1;
}

int help(object me)
{
  write(@HELP
ָ���ʽ : award <�����> <����> <����>

��ָ�������(��)�����������ʤ����ҡ�
���ӣ�
award sdong title $HIR$��������
award sdong 9yin granted

HELP
	 );
	 return 1;
}

