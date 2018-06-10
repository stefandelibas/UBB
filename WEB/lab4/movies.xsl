<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
	<xsl:template match="/">
		<html> 
			<head>
				<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css"/>
			</head>
			<body>
				<h2>Movies</h2>
				<table border="1">
					<tr>
						<th>Title</th>
						<th>Actors</th>
						<th>Genre</th>
						<th>Date</th>
						<th>Duration</th>
					</tr>

					<xsl:for-each select="movies/movie">
						<tr>
							<td><xsl:value-of select="title"/></td>
							<td>
								<xsl:for-each select=".//actor">
									<ul>
										<li>
											<xsl:value-of select="."/>
										</li>
									</ul>
								</xsl:for-each>
							</td>
							<xsl:choose>  
									<xsl:when test="genre='Comedy'">  
										<td class="bg-danger">
											<xsl:value-of select="genre"/>
										</td>
									</xsl:when> 
									<xsl:when test="genre='Drama'">  
										<td class="bg-primary">
											<xsl:value-of select="genre"/>
										</td>
									</xsl:when>
									<xsl:when test="genre='Action'">  
										<td class="well">
											<xsl:value-of select="genre"/>
										</td>
									</xsl:when>
									<xsl:when test="genre='Thriller'">  
										<td class="mark">
											<xsl:value-of select="genre"/>
										</td>
									</xsl:when> 
								</xsl:choose>  
							
							<td><xsl:value-of select="date-of-playing"/></td>
							<td><xsl:value-of select="duration"/></td>
						</tr>
					</xsl:for-each>
				</table>
			</body>
		</html>
	</xsl:template>
</xsl:stylesheet>

