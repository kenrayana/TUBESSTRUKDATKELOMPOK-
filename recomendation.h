#ifndef RECOMMENDATION_H
#define RECOMMENDATION_H

#include "songlibrary.h"
#include "playlist.h"
#include "genreorder.h"

Playlist* generateRecommendation(SongLibrary &lib, GenreOrder &pref);

#endif

