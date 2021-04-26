//Cracked by Kafei
// skill.c
// From ES2
// Modified by Xiang for XKX (12/15/95)

#include <ansi.h>
#include <dbase.h>

mapping skills;
mapping learned;
mapping skill_map;
mapping skill_prepare;
mapping marry_learn;
mapping query_skills() { return skills; }
mapping query_learned() { return learned; }
mapping query_marry_learn() { return marry_learn; }

void set_skill(string skill, int val)
{
	if( !find_object(SKILL_D(skill))
	&&	file_size(SKILL_D(skill)+".c") < 0 )
		error("F_SKILL: No such skill (" + skill + ")\n");

	if( !mapp(skills) ) skills = ([ skill: val ]);
	else skills[skill] = val;
}
void add_marry_learn(string skill, int val)
{
	if( !find_object(SKILL_D(skill))
	&&	file_size(SKILL_D(skill)+".c") < 0 )
		error("F_SKILL: No such skill (" + skill + ")\n");
	if( !mapp(marry_learn) ) marry_learn = ([ skill: val ]);
	else marry_learn[skill] = val;
}

int delete_skill(string skill)
{
	if( mapp(skills) ) {
		map_delete(skills, skill);
		if( mapp(learned) ) {
			map_delete(learned, skill);
			return undefinedp(learned[skill]);
		}
		return undefinedp(skills[skill]);
	}
	return 0;
}

// This function 'map' a skill <skill> to another skill <mapped_to>.
// If 2nd argument not given, cancel the mapped skill <skill>.
varargs void map_skill(string skill, string mapped_to)
{
	if( !mapped_to && mapp(skill_map) ) {
		map_delete(skill_map, skill);
		return;
	}

	if( !find_object(SKILL_D(skill))
	&&	file_size(SKILL_D(skill)+".c") < 0 )
		error("F_SKILL: No such skill (" + skill + ")\n");

	if( !mapp(skills) || undefinedp(skills[mapped_to]) )
		return;
		
	if( !mapp(skill_map) ) skill_map = ([ skill: mapped_to ]);
	else skill_map[skill] = mapped_to;
}

// This function 'prepare' a skill <skill> to another skill <mapped_to>.
// If 2nd argument not given, cancel the prepared skill <skill>.
varargs void prepare_skill(string skill, string mapped_to)
{
	if( !mapped_to && mapp(skill_prepare) ) {
		map_delete(skill_prepare, skill);
		return;
	}

	if( !find_object(SKILL_D(skill))
	&&	file_size(SKILL_D(skill)+".c") < 0 )
		error("F_SKILL: No such skill (" + skill + ")\n");

	if( !mapp(skills) || undefinedp(skills[mapped_to]) )
		return;
		
	if( !mapp(skill_prepare) ) skill_prepare = ([ skill: mapped_to ]);
	else skill_prepare[skill] = mapped_to;
}

string query_skill_mapped(string skill)
{
	if( mapp(skill_map) && !undefinedp(skill_map[skill]) )
		return skill_map[skill];
	return 0;
}

string query_skill_prepared(string skill)
{
	if( mapp(skill_prepare) && !undefinedp(skill_prepare[skill]) )
		return skill_prepare[skill];
	return 0;
}

varargs int query_skill(string skill, int raw)
{
	if( !raw ) {
		int s;
		
		s = query_temp("apply/" + skill);
		if( mapp(skills) ) {
			s += skills[skill] / 2;
			if( mapp(skill_map) )
				s += skills[skill_map[skill]];
		}
		return s;
	}
	if( mapp(skills) && !undefinedp(skills[skill]) ) return skills[skill];
	return 0;
}

mapping query_skill_map()
{
	return skill_map;
}

mapping query_skill_prepare()
{
	return skill_prepare;
}

int skill_death_penalty()
{
	string *sk;
	int i;

	if( wizardp(this_object()) || !mapp(skills) ) return 0;

	sk = keys(skills);
	if( !mapp(learned) )
		for(i = 0; i<sizeof(sk); i++) {
			skills[sk[i]]--;
			if( skills[sk[i]]<0 ) map_delete(skills, sk[i]);
			else learned = ([sk[i] : (skills[sk[i]]+1) * (skills[sk[i]]+1) / 2]);
		}
	else
		for(i = 0; i<sizeof(sk); i++) {
			if( (int)learned[sk[i]] > (skills[sk[i]]+1) * (skills[sk[i]]+1) / 2 )
				learned[sk[i]] -= (skills[sk[i]]+1) * (skills[sk[i]]+1) / 2;
			else {
				skills[sk[i]]--;
				if( skills[sk[i]]<0 ) map_delete(skills, sk[i]);
				else learned[sk[i]] += (skills[sk[i]]+1) * (skills[sk[i]]+1) / 2;
			}
		}
	skill_map = 0;
	return 1;
}

varargs void improve_skill(string skill, int amount, int weak_mode)
{
	int spi;

	if (!userp(this_object()))
		return;
	if( !find_object(SKILL_D(skill))
	&&	file_size(SKILL_D(skill)+".c") < 0 )
		error("F_SKILL: No such skill (" + skill + ")\n");

	if( !weak_mode || !userp(this_object()) ) {
		if( !mapp(skills) ) skills = ([]);
		if( undefinedp(skills[skill]) ) skills[skill] = 0;
	}

	// Give learning penalty to those learning too much skills.
//	spi = query("spi");
	spi = 30; // set the default maximum to be 30 (CLEANSWORD CHANGED AT 5/27/96)
	if( sizeof(learned) > spi )
		amount /= sizeof(learned) - spi;

	if( !amount ) amount = 1;

	if( !mapp(learned) ) learned = ([ skill : amount ]);
	else (int)learned[skill] += amount;

	if( (!weak_mode || !userp(this_object()))
	&&	learned[skill] > (skills[skill] + 1) * (skills[skill] + 1) ) {
		skills[skill]++;
		learned[skill] = 0;
		tell_object(this_object(), HIC "��ġ�" + to_chinese(skill) + "�������ˣ�\n" NOR);
		SKILL_D(skill)->skill_improved(this_object());
	}
}

varargs void remove_skill(string skill, int amount)
{
	int x;
	if (!userp(this_object()))
		return;

	if( !find_object(SKILL_D(skill))
	&&	file_size(SKILL_D(skill)+".c") < 0 )
		error("F_SKILL: No such skill (" + skill + ")\n");

	if( !amount ) amount = 1;
	if( mapp(learned) && amount < learned[skill] ) (int)learned[skill] -= amount;
	else {
		if(!mapp(learned)){
			learned = ([ skill : skills[skill]*skills[skill] ]);
			skills[skill]--;
		}

		for(x=0;amount>(int)learned[skill];x++)
		{
			(int)learned[skill] += skills[skill]*skills[skill];
			skills[skill]--;
		}
		if ((int)skills[skill] < 0) delete_skill(skill);
		else (int)learned[skill] -= amount;	
	}
	SKILL_D(skill)->skill_improved(this_object());
}
int max_skill(float exper)
{
	int level, max_lvl;

	if ( exper <= 1600000.0 )//max to 238, add next lvl need 1.71M.
        	max_lvl = ceil( pow( 8000000.0, 0.333333) );
        else if ( exper <= 3200000.0 )//max to 294, add next lvl need 3.42M.
        	max_lvl = ceil( pow( 13600000.0, 0.333333) );
        else if ( exper <= 4800000.0 )//max to 330, add next lvl need 5.18M.
        	max_lvl = ceil( pow( 25600000.0, 0.333333) );
        else if ( exper <= 6400000.0 )//max to 355, add next lvl need 6.94M.
        	max_lvl = ceil( pow( 36000000.0, 0.333333) );
        else if ( exper <= 8000000.0 )//max to 373, add next lvl need 8.71M.
        	max_lvl = ceil( pow( 38400000.0, 0.333333) );
        else if ( exper <= 9600000.0 )//max to 386, add next lvl need 10.53M.
        	max_lvl = ceil( pow( 52000000.0, 0.333333) );
        else if ( exper <= 11200000.0 )//max to 394, add next lvl need 12.32M.
        	max_lvl = ceil( pow( 57600000.0, 0.333333) );
        else if ( exper <= 12800000.0 )//max to 400, add next lvl need 14.35M.
        	max_lvl = ceil( pow( 61600000.0, 0.333333) );
        else if ( exper <= 19200000.0 )//max to 442, add next lvl need 21.80M.
        	max_lvl = ceil( pow( 64000000.0, 0.333333) );
        else if ( exper <= 25600000.0 )//max to 467, add next lvl need 29.30M.
        	max_lvl = ceil( pow( 86400000.0, 0.333333) );
        else if ( exper <= 32000000.0 )//max to 482, add next lvl need 37.56M.
        	max_lvl = ceil( pow( 102400000.0, 0.333333) );
        else max_lvl = ceil( pow( 112000000.0, 0.333333) );

	if ( exper <= 800000.0 ) //max to 200, add next lvl need 0.96M.
        	level = ceil( pow( exper*10.0, 0.333333) );
        else if ( exper <= 1600000.0 )//max to 238, add next lvl need 1.71M.
        	level = ceil( pow( exper*8.5, 0.333333) );
        else if ( exper <= 3200000.0 )//max to 294, add next lvl need 3.42M.
        	level = ceil( pow( exper*8.0, 0.333333) );
        else if ( exper <= 4800000.0 )//max to 330, add next lvl need 5.18M.
        	level = ceil( pow( exper*7.5, 0.333333) );
        else if ( exper <= 6400000.0 )//max to 355, add next lvl need 6.94M.
        	level = ceil( pow( exper*7.0, 0.333333) );
        else if ( exper <= 8000000.0 )//max to 373, add next lvl need 8.71M.
        	level = ceil( pow( exper*6.5, 0.333333) );
        else if ( exper <= 9600000.0 )//max to 386, add next lvl need 10.53M.
        	level = ceil( pow( exper*6.0, 0.333333) );
        else if ( exper <= 11200000.0 )//max to 394, add next lvl need 12.32M.
        	level = ceil( pow( exper*5.5, 0.333333) );
        else if ( exper <= 12800000.0 )//max to 400, add next lvl need 14.35M.
        	level = ceil( pow( exper*5.0, 0.333333) );
        else if ( exper <= 19200000.0 )//max to 442, add next lvl need 21.80M.
        	level = ceil( pow( exper*4.5, 0.333333) );
        else if ( exper <= 25600000.0 )//max to 467, add next lvl need 29.30M.
        	level = ceil( pow( exper*4.0, 0.333333) );
        else if ( exper <= 32000000.0 )//max to 482, add next lvl need 37.56M.
        	level = ceil( pow( exper*3.5, 0.333333) );
        else level = ceil( pow( exper*2.5, 0.333333) );
	if ( (exper > 800000.0 || exper > 1600000.0 || exper > 3200000.0 || exper > 4800000.0 || exper > 6400000.0
	 || exper > 8000000.0 || exper > 9600000.0 || exper > 11200000.0 || exper > 12800000.0 || exper > 19200000.0
	 || exper > 25600000.0 || exper > 32000000.0) && level <= max_lvl )
	level = max_lvl;
	return level;
}
